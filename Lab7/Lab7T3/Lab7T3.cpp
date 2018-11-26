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

	
	input.close();

	input.open("input.txt");

	for (int i = 0; i < counter; ++i) {
		input.get(ch);
		arr[i] = ch;
	}

	for (int i = 0; i < counter; ++i) {
		cout << arr[i];
	}
	cout << endl;

	int twoLetterCount = 0;
	for (int i = 1; i < counter; ++i) {
		cout << arr[i];
		if ((isdigit(arr[i]) > 0) && (isdigit(arr[i - 1]) > 0) ){

			cout << "shit\n";
			twoLetterCount++;
			
		}
	}
	cout << twoLetterCount << endl;
	input.close();
	system("pause");

	return 0;

}
