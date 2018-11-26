/*Найти количество различных цифр в записи заданного натурального числа n(разработать алгоритмы с использованием и без использования массивов).
В данном случае с использованием массива
Юсевич 1 группа

Тесты:

Enter num: 511
Quantity of unique digits is: 2

Enter num: 985553255
Quantity of unique digits is: 5

Enter num: -1415
Invalid data


*/


#include <iostream>

using namespace std;

int main()
{
	int quantity = 0;//количество уникальных цифр числа
	int num, digits[10] = { 0 };

	cout << "Enter num: ";
	cin >> num;

	if (num >= 0) {

		if (num == 0)
			digits[0]++;

		while (num > 0)
		{
			digits[num % 10]++;
			num /= 10;
		}

		for (int i = 0; i < 10; i++) {

			if (digits[i] > 0) {
				quantity++;
			}
		}

		cout << "Quantity of unique digits is: " << quantity << endl;
	}
	else {
		cout << "Invalid data\n";
	}
		system("pause");
		return 0;
}



	
	


