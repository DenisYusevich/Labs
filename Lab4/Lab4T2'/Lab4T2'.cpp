/*Дан массив целых чисел, из этой последовательности целых чисел выбрать три числа, произведение которых максимально.
Юсевич Денис 1 группа

Тесты:

Enter size of array: 10
Enter members of array: 3
6
-5
-9
4
1
3
2
1
2

-9 -5 6


Enter size of array: 9
Enter members of array: -6
-6
1
4
8
9
8
3
6

9 8 8

Enter size of array: 10
Enter members of array: -5
-6
-1
-8
-2
-5
-3
-7
-4
-9

-1 -2 -3


*/



#include<iostream>

using namespace std;


void sort(int *arr, int size) {//функция сортировки выбором

	int min, temp;

	for (int i = 0; i < size - 1; ++i) {

		min = i;
		for (int k = i + 1; k < size; ++k) {

			if (arr[k] < arr[min]) {
				min = k;
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

	cout << "Enter members of array: ";

	int *arr = new int[sizeOfArr];//создаем динамический массив
	
	for (int i = 0; i < sizeOfArr; ++i) {

		cin >> arr[i];

	}

	cout << endl;

	sort(arr, sizeOfArr);


	if (arr[sizeOfArr - 1] * arr[sizeOfArr - 2] * arr[sizeOfArr - 3] > arr[0] * arr[1] * arr[sizeOfArr - 1]) {

		cout << arr[sizeOfArr - 1] << " " << arr[sizeOfArr - 2] << " " << arr[sizeOfArr - 3] << " " << endl;

	}
	else {

		cout << arr[0] << " " << arr[1] << " " << arr[sizeOfArr - 1] << endl;

	}

	system("pause");
	return 0;

	


}