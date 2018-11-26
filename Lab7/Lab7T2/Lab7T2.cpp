#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


char* Erase(char *str, int pos, int n) {
	char *buff;
	int i = 0, len;
	len = strlen(str); // нашли длину строки

	if (len >= pos + n)
	{
		buff = new char[len - n];
		while (i != pos) // сдвигаем "манипулятор" i до положения pos
		{
			buff[i] = str[i]; // при этом копируем содержимое строки в буфер
			i++;
		}
		while (i != len - n) // просто копируем символы из строки в буфер, пропуская n штук
		{// которые идут после pos
			buff[i] = str[i + n];
			i++;
			if (i == len - n)buff[i] = '\0'; // обрезаем строку в буфере.
		}
		str = buff; // копируем содержимое буфера в строку      
	}
	return str;// возвращаем строку
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