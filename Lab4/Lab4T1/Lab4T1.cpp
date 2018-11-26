/*ƒан массив целых чисел, в котором все числа кроме одного встречаютс€ четное количество раз,
одно число встречаетс€ нечетное количество раз. Ќайти это число.
ёсевич ƒенис 1 группа

“есты:

Enter quantity of numbers: 9
Enter numbers: 5
3
5
3
5
2
2
4
4

Odd is: 5

Enter quantity of numbers: 5
Enter numbers: 2
2
3
1
1

Odd is: 3




*/



#include<iostream>

using namespace std;

int main() {

	int size;

	cout << "Enter quantity of numbers: ";
	cin >> size;

	int counter = 1;

	int *arr = new int[size];//создаем динамический массив

	cout << "Enter numbers: ";
	

	for (int i = 0; i < size; ++i) {//заполн€ем массив элементами

		cin >> arr[i];

	}

	for (int i = 0; i < size; ++i) {/*пробегаемс€ по массиву, когда находим такое же число, увеличиваем счетчик,
											если на счетчике четное количество,обнул€ем эти элементы массива,таким образом 
											ненулевым остаетс€ лишь элемент массива, встречающийс€ нечетное кол-во раз*/


		counter = 1;

		for (int k = i + 1; k < size; ++k) {
			
			if (arr[i] == arr[k]) {

				counter++;
				if (counter % 2 == 0) {

					arr[k] = 0;
					arr[i] = 0;

				}	
			}
		}
	}


	for (int i = 0; i < size; ++i) {

		if (arr[i] != 0) {
			cout << "\n";
			cout << "Odd is: " << arr[i] << endl;;
		}
	}
	system("pause");
	return 0;

}