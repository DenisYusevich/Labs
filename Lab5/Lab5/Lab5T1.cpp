/*Дана квадратная матрица n-го порядка, состоящая из целых чисел. Определить является ли она магическим квадратом 
Юсевич Денис 1 группа

Тесты:

2
7
6

9
5
1

4
3
8

Matrix is magical


3
4
5

7
1
2

6
0
1

Matrix is not magical





*/


#include <iostream>

using namespace std;


bool isValid(int *check, int k) {
	bool flag = true;

	for (int i = 0; i <= k; ++i) {
		for (int j = i + 1; j <= k; ++j) {
			if (check[i] == check[j]) {
				cout << "Invalid input,should be no similiar numbers\n";
				flag = false;
				break;

			}
		}if (flag == false) {
			break;
		}
	}
	if (flag == false) {
		return false;
	}
	else {
		return true;
	}
}




int main()
{
	const int N = 3;
	int matrix[N][N];
	int check[N*N];
	int k = -1;
	

	for (int i = 0; i < N; i++)
	{
		
		for (int j = 0; j < N; j++)
		{
			k++;
			cin >> matrix[i][j] ;
			check[k] = matrix[i][j];

		}
		cout << "\n";
	}


	/*for (int i = 1; i <= k; ++i) {
		cout << check[i]<<" ";

	}*/

	/*for (int i = 0; i <= k; ++i) {
		for (int j = i+1; j <= k; ++j) {
			if (check[i] == check[j]) {
				cout << "God damn!\n";
				isValid = false;
				break;
			}
		}if (isValid == false) {
			break;
		}
	}
*/
	int sumOfRow[N], sumOfCol[N], sumOfDiag[2];


	if (isValid(check,k) == true) {
		for (int i = 0; i < N; i++)
		{
			sumOfDiag[0] += matrix[i][i];
			sumOfDiag[1] += matrix[(N - 1) - i][(N - 1) - i];

			for (int j = 0; j < N; j++)
			{
				sumOfRow[i] += matrix[i][j];
				sumOfCol[i] += matrix[j][i];
			}

			if (sumOfCol[i] != sumOfRow[i])
			{
				cout << "Matrix is not magical\n" << endl;
				break;
			}
			else if ((i > 0) && (sumOfRow[i] != sumOfRow[i - 1]))
			{
				cout << "Matrix is not magical\n" << endl;
				break;
			}
			else if ((i > 0) && (sumOfCol[i] != sumOfCol[i - 1]))
			{
				cout << "Matrix is not magical\n" << endl;
				break;
			}
		}

		if ((sumOfDiag[0] == sumOfDiag[1]) && (sumOfCol[0] == sumOfDiag[0]))
			cout << "Matrix is magical\n";

	}
	system("pause");

	return 0;
}