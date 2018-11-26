#include<iostream>
#include<fstream>

using namespace std;

const char operators[36][3] = { "+", "-", "*", "/", "!", "=", "%", "~", "&", "|", "^", "*", ".", "?", ":", ">", "<",
										  "<<", ">>", "<=", "<=", "++", "--", "==", "!=", "&&", "||", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "+=", "^=" };


bool isoperation(char c) {
	for (int i = 0; i < 17; i++)
		if (c == operators[i][0]) return true;
	return false;
}

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

	int operCounter = 0;
	for (int i = 0; i < counter; ++i) {

		if (isoperation(arr[i]) == true) {
			cout << arr[i]<<" ";
			operCounter++;
		}
	}

	cout << operCounter << endl;
	input.close();
	system("pause");
	return 0;
}