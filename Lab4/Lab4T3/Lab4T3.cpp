/*Дан массив целых чисел. Реализовать функцию для обработки массива целых чисел. Функция находит минимальный элемент массива и сортирует все элементы левее его по убыванию,
а правее его – по возрастанию. Функция возвращает индекс минимального элемента. 
Юсевич Денис 1 группа

Тесты:

Enter size of array: 8
Enter members of array: 5
9
3
2
1
9
5
2

Index of  min is: 4
9 5 3 2 1 2 5 9

Enter size of array: 8
Enter members of array: 3
3
3
3
3
3
3
3

Index of  min is: 0
3 3 3 3 3 3 3 3

Enter size of array: 10
Enter members of array: 4
1
9
4
8
-1
3
2
7
6

Index of  min is: 5
9 8 4 4 1 -1 2 3 6 7




*/




#include<iostream>

using namespace std;


void sort(int *arr, int min, int size) {//функция сортировки выбором

	int temp, max;

	for (int i = 0; i < min - 1; ++i) {

		max = i;
		for (int j = i + 1; j < min; ++j) {

			if (arr[j] > arr[max]) {

				max = j;

			}
		}
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;

	}


	for (int i = min; i < size - 1; ++i) {

		min = i;
		for (int j = i + 1; j < size; ++j) {

			if (arr[j] < arr[min]) {

				min = j;
			}

		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

}


int main() {

	int sizeOfArr;

	cout << "Enter size of array: ";
	cin >> sizeOfArr;

	int *arr = new int[sizeOfArr];//динамический массив

	cout << "Enter members of array: ";

	for (int i = 0; i < sizeOfArr; ++i) {

		cin >> arr[i];
	}
	cout << endl;

	int min = 0;
	for (int i = 0; i < sizeOfArr; ++i) {//определяем индекс минимального элемента

		if (arr[i] < arr[min]) {

			min = i;

		}
	}
	cout << "Index of  min is: " << min << endl;

	sort(arr, min, sizeOfArr);

	for (int k = 0; k < sizeOfArr; ++k) {

		cout << arr[k] << " ";

	}
	cout << endl;

	system("pause");
	return 0;

}