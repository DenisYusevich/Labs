#include<iostream>
#include<fstream>

using namespace std;

const int MAX_OPERATORS = 36;

int operators_count[MAX_OPERATORS] = { 0 };

const char operators[36][3] = { "+", "-", "*", "/", "!", "=", "%", "~", "&", "|", "^", "*", ".", "?", ":", ">", "<",
										  "<<", ">>", "<=", "<=", "++", "--", "==", "!=", "&&", "||", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "+=", "^=" };


bool isoperation(char c) {
	for (int i = 0; i < 17; i++)
		if (c == operators[i][0]) return true;
	return false;
}

void count_operator(char* c) {
	for (int i = 0; i < MAX_OPERATORS; i++)
		if (strcmp(c, operators[i]) == 0) {
			operators_count[i]++;
			break;
		}
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



	int len = strlen(arr);
	int i = 0;
	while (i < len) {
		if (isoperation(arr[i])) {
			if (isoperation(arr[i + 1])) {
				arr[i + 2] = '\0';
				count_operator(arr + i);
				i += 3;
			}
			else {
				arr[i + 1] = '\0';
				count_operator(arr + i);
				i += 2;
			}
		}
		else if (arr[i] == '\"') {
			while (arr[++i] != '\"');
			i++;
		}
		else i++;
	}
	for (int i = 0; i < MAX_OPERATORS; i++)
		if (operators_count[i])
			cout << "Operator " << operators[i] << " is used " << operators_count[i] << ((operators_count[i] > 1) ? " times\n" : " time\n");
	system("pause");
	return 0;
}
