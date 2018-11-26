/*Написать функцию, которая производит двоичный поиск места размещения нового элемента в упорядоченном массиве и возвращает указатель на место включения нового элемента.
С помощью данной функции реализовать сортировку вставками.
Юсевич Денис 1 группа

Тесты:

Enter n: 5
8
0
3
4
1
0 1 3 4 8

Enter n: -5
Invalid data

*/



#include <iostream>

using namespace std;


int* binSearch(int* arr, int n, int key) {
	int left = 0, right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid;
	}
	return arr + left;
}

void binInsertSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int* k = binSearch(a, i, a[i]);
		for (int j = i - 1; j >= (k - a); j--)
			swap(a[j], a[j + 1]);
	}
}

int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	if (n <= 0) {
		cout << "Invalid data\n";
	}
	if (n > 0) {
		int *arr = new int[n];
		cout << "Enter elments: \n";
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		binInsertSort(arr, n);
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";

		delete[] arr;
	}
	system("pause");
	return 0;
}
