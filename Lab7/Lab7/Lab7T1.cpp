#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

int main() {

	
	ifstream input("input.txt"); 

	char ch;
	int counter = 0;
	while (input.get(ch))
	{
		
		counter++;
	}
	char* arr = new char[counter];
	
	cout << counter;
	input.close();

	input.open("input.txt");

	for (int i = 0; i < counter; ++i) {
		input.get(ch);
		arr[i] = ch;
	}

	for (int i = 0; i < counter; ++i) {
		cout << arr[i];
	}

	int alphaCounter = 0;
	int numCounter = 0;
	int otherCounter = 0;

	for (int i = 0; i < counter; ++i) {
		if (isalpha(arr[i])>0) {
			alphaCounter++;
		}
		if (isdigit(arr[i])>0) {
			numCounter++;
		}
		if (isdigit(arr[i]) <=0 && isalpha(arr[i])<=0) {
			otherCounter++;
		}
	}


	cout << "Count of letters: " << alphaCounter << endl << "Count of digits: " << numCounter << endl << "Other symbols: " << otherCounter << endl;

	input.close();

	delete [] arr;
	

	system("pause");
	return 0;

}