#include <iostream>
#include <cstring>
#include<fstream>

using namespace std;


char reverseString(char *str)
{
	char p[128];

	strcpy_s(p, str);
	int i = 0;
	int j = strlen(p) - 1;
	while (i <= j + i)
		str[i++] = p[j--];

	return *str;
}


char* findingWord(char* str,int counter,int j) {

	
	while (str[j] != ' ') {
		j++;

	}

	char* str1 = new char[j];

	strncpy_s(str1, counter, str, j);
	
	reverseString(str1);
	
	return str1;

}


int main() {

	ifstream input("input.txt");//REMAKE INPUT
	
	char ch;
	int counter = 0;
	while (input.get(ch))
	{

		counter++;
	}
	char* str = new char[counter];

	
	input.close();

	input.open("input.txt");

	for (int i = 0; i < counter; ++i) {
		input.get(ch);
		str[i] = ch;
	}

	for (int i = 0; i < counter; ++i) {
		cout << str[i];
	}
	
	char* strWord = new char[1];
	char* finalStr = new char[1];
	
	/*int k = -1;
	int j = -1;
	while (k < 4) {
		k++;
		strWord = findingWord(str, counter,j);
		j = j + strlen(strWord);
		strcat_s(finalStr,strlen(finalStr), strWord);
	}*/
	finalStr = findingWord(str, counter, -1);
	strWord = findingWord(str, counter, 5);

	//strcat_s(finalStr, strlen(finalStr), strWord);

	cout << endl;
	cout << strWord;
	
	input.close();

	system("pause");
	return 0;
}