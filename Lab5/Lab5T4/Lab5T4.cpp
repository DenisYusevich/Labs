/*Написать программу, которая содержит функцию, принимающую в качестве аргумента, указатели на два массива (А и В) и размеры массивов. Функция проверяет,
является ли массив В подмножеством/построкой (2 способами, см. зам.) 
массива А и возвращает указатель на начало найденного фрагмента, если элемента нет, возвращает 0.
Юсевич Денис 1 гуппа

Тесты:


Enter elemnts of A: 5
4
7
3
2

Enter elements of B: 5
4
7
8
8
Array B is not subset of A
Array B is subset of A


Enter elemnts of A: 4
7
8
2
2

Enter elements of B: 3
8
7
4
2
Array B is subset of A
Array B is subset of A






*/



#include <iostream>


using namespace std;

int findingMin(int x, int y) {
	return (x > y) ? y : x;
}

	

void subsetDecider1(int* a, int n, int* b, int m) {
	bool isSubSet = true;
	for (int i = 0; i < m; ++i) {
		bool isBinA = false;
		for (int j = 0; j < n; ++j) {
			if (a[j] == b[i]) {
				isBinA = true;
			}
		}
		isSubSet = isBinA;
	}
	if (isSubSet) {
		cout << "Array B is subset of A";
	}
	else {
		cout << "Array B is not subset of A";
	}
}

void subsetDecider2(int *a, int n, int *b, int m) {
	int min = 10000;
	for (int i = 0; i < n; ++i) {
		min = findingMin(min, a[i]);
	}

	bool c[10000] = { 0 };

	if (min > 0) {
		min = 0;
	}

	for (int i = 0; i < n; ++i) {
		c[a[i] - min] = true;
	}
	bool isWrite = false;

	for (int i = 0; i < m; ++i) {
		
		if (b[i] - min < 0) {
			cout << "Array B is subset of A";
			isWrite = true;
			break;
		}
		if (!c[b[i] - min]) {
			cout << "Array B is subset of A";
			isWrite = true;
			break;
		}
	}
	if (!isWrite) {
		cout << "Array B is subset of A";
	}
}


int main() {
	const int SIZE1 = 5;
	const int SIZE2 = 5;
	int a[SIZE1];
	int b[SIZE2];
	
	cout << "Enter elemnts of A: ";
	for (int i = 0; i < SIZE1; ++i) {
		cin >> a[i];
	}
	cout << endl;
	cout << "Enter elements of B: ";
	for (int i = 0; i < SIZE2; ++i) {
		cin >> b[i];
	}

	subsetDecider1(a, SIZE1, b, SIZE2);
	cout << endl;
	subsetDecider2(a, SIZE1, b, SIZE2);
	
	system("pause");
	return 0;
}