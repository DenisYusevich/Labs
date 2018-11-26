#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


char* Erase(char *str, int pos, int n) {
	char *buff;
	int i = 0, len;
	len = strlen(str); // ����� ����� ������

	if (len >= pos + n)
	{
		buff = new char[len - n];
		while (i != pos) // �������� "�����������" i �� ��������� pos
		{
			buff[i] = str[i]; // ��� ���� �������� ���������� ������ � �����
			i++;
		}
		while (i != len - n) // ������ �������� ������� �� ������ � �����, ��������� n ����
		{// ������� ���� ����� pos
			buff[i] = str[i + n];
			i++;
			if (i == len - n)buff[i] = '\0'; // �������� ������ � ������.
		}
		str = buff; // �������� ���������� ������ � ������      
	}
	return str;// ���������� ������
}

int main() {

	ifstream input("input.txt");

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

	cout << "\n";

	


	input.close();

	

	system("pause");

	return 0;

}