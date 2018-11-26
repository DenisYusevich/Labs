/*Найти сумму и произведение двух многочленов, заданных массивами своих коэффициентов.
Юсевич Денис 1 группа

тесты:

Enter quantity 1: 3
Enter quantity 2: 2
Enter coefficients: 1
2
3


Enter coefficients: 1
2


Enter x: 2
Sum is: 22


Enter quantity 1: 4
Enter quantity 2: 5
Enter coefficients: -1
3
5
2


Enter coefficients: 1
-5
3
6
2


Enter x: -1
 Sum is: 4


 Enter quantity 1: -4
Enter quantity 2: 5
Invalid data



*/





#include<iostream>

using namespace std;



void enterCoefficients(int *arr,int size) {//функция,считывающая коэффициенты

	cout << "Enter coefficients: ";

	for (int i = 0; i < size; ++i) {

		cin >> arr[i];

	}
	cout << endl << endl;
}

int sumOfOne(int *arr,int size,int x) {//функция, суммирующая члены одного многочлена

	int sum = 0;

	for (int j = size - 1; j >= 0; --j) {

		sum += arr[j] * pow(x, j);
		
	}
	return sum;
}

int main() {

	int size1;
	int size2;
	int x;
	int finalSum;


	cout << "Enter quantity 1: ";
	cin >> size1;
	cout << "Enter quantity 2: ";
	cin >> size2;

	if (size1 > 0 && size2 > 0) {
		int *arr1 = new int[size1];//создаем 2 динамических массива
		int *arr2 = new int[size2];



		enterCoefficients(arr1, size1);
		enterCoefficients(arr2, size2);

		cout << "Enter x: ";
		cin >> x;


		finalSum = sumOfOne(arr1, size1, x) + sumOfOne(arr2, size2, x);//считаем сумму двух многочленов

		cout << " Sum is: " << finalSum << endl;
	}
	else {
		cout << "Invalid data\n";
	}
	
	system("pause");
	return 0;

}