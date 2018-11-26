/*Добавить к некоторой последовательности  A=(ai), i=1..n, n<=100, наименьшее  число элементов,  чтобы  получить 
арифметическую прогрессию (например, 22 1  36  -> 1  8 15 22 29 36).
Юсевич Денис 1 группа

Тесты:

Quantity? 3
Enter nums: 22
1
36
1 8 15 22 29 36


Quantity? 5
Enter nums: 3
9
30
39
57
3 6 9 12 15 18 21 24 27 30 33 36 39 42 45 48 51 54 57


Quantity? -5
Invalid data,quantity should be higher than 1

Quantity? 3
Enter nums: 3
3
3
Invalid data,should be no duplicating numbers

*/




#include<iostream>

using namespace std;


int sum = 0;
int nod;//НОД
int finalQuantity;
int min;



void sort(int *arr, int size) {//функция сортировки выбором

	int temp, max;
	

	for (int i = 0; i < size - 1; ++i) {

		max = i;
		for (int j = i + 1; j < size; ++j) {

			if (arr[j] > arr[max]) {

				max = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}
}

void findingNOD(int *delta,int divider,int q) {//функция нахождения НОДа
	int addend;

	while (divider > 0) {

		sum = 0;

		for (int i = 0; i < q - 1; ++i) {

			addend = delta[i] % divider;

			sum += addend;
		}
		if (sum > 0) {
			divider--;
		}
		if (sum == 0) {
			nod = divider;
			break;
		}
	}
}


void findingMin(int *delta,  int q) {//функция для нахождения индекса минимального элемента

	int min = 0;
	for (int i = 0; i < q - 1; ++i) {

		if (delta[i] < delta[min]) {

			min = i;
		}
	}
}

int main() {


	int quantity;

	cout << "Quantity? ";
	cin >> quantity;

	if (quantity > 1) {

		int *arr = new int[quantity];//создание динам массива

		cout << "Enter nums: ";
		for (int i = 0; i < quantity; ++i) {

			cin >> arr[i];
		}

		sort(arr, quantity);

		int *delta = new int[quantity - 1];//создание еще одного динам массива, в котором будут находиться разности между соседними элементами массива
		for (int i = 0; i < quantity - 1; ++i) {

			delta[i] = arr[i] - arr[i + 1];
			if (delta[i] == 0) {//проверка на дублирующиеся числа
				cout << "Invalid data,should be no duplicating numbers\n";
				system("pause");
				return 0;
			}
		}


		findingMin(delta, quantity);//вычисляем минимальный элемент 

		int divider = delta[min];//будем делить каждый элемент на этот минимальный(см функцию findingNOD)

		findingNOD(delta, divider, quantity);//находим НОД

		finalQuantity = ((arr[0] - arr[quantity - 1]) / nod) + 1;//вычисляем количество элементов массиве с арифметической прогрссией


		int *progression = new int[finalQuantity];//динам массив для прогрессии
		progression[0] = arr[quantity - 1];
		cout << progression[0] << " ";

		for (int k = 1; k < finalQuantity; ++k) {//заполняем массив и выводим прогрессию на экран
			progression[k] = progression[k - 1] + nod;
			cout << progression[k] << " ";
		}

		cout << endl;
	}
	else {
		cout << "Invalid data,quantity should be higher than 1\n";
	}

	system("pause");
	return 0;

}//polniy spravochnik Shildta,pradt 2012//shildt 10 god ctr 23s xepom