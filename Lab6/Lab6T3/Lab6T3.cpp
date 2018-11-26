#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;



////void addColsInMatrix(int **A, const int n, const int m)
//{
//	const int M = m + m / 2;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 2; j < M; j += 3)
//		{
//			for (int k = M; k > j; k--) A[i][k] = A[i][k - 1];
//			A[i][j] = 0;
//		}
//	}
//
//}
void deleteCol() {




}


void deleteRow(int **arr, int row, int col, int key) {

	int** arr2 = new int*[row-1];//создаем динамический двумерный массив

	for (int i = 0; i < row-1; i++) {

		arr2[i] = new int[col];

	}

	for (int i = 0; i < row-1; i++) {
		for (int j = 0; j < col; j++) {
			if (i >= key - 1) {
				arr2[i][j] = arr[i + 1][j];
			}
			else {
				arr2[i][j] = arr[i][j];
			}
		}
	}

	for (int i = 0; i < row-1; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(10) << arr2[i][j];
		}cout << endl;
	}

}


void insertRow(int **arr, int row, int col, int key) {
	
	int	j = key - 1;

	for (int i = 0; i < col; ++i) {
		for (int k = row ; k >= j + 1; --k) {
			arr[k][i] = arr[k-1][i];

		}
	}

	cout << "wtf\n";

	for (int i = 0; i < col; ++i) {
		arr[j][i] = 0;
	}

	for (int i = 0; i < row + 1; i++) {
		for (int j = 0; j < col ; j++) {
			cout << setw(10) << arr[i][j];
		}cout << endl;
	}


}

int insertCol(int **arr, int row, int col,int key) {

	int	j = key - 1;
	
	for (int i = 0; i < row; ++i) {
		for (int k = col ; k >= j + 1; --k) {
			arr[i][k] = arr[i][k - 1];
			
		}
	}

	
	for (int i = 0; i < row; ++i) {
		arr[i][j] = 0;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col + 1; j++) {
			cout << setw(10) << arr[i][j];
		}cout << endl;
	}
	return 0;
}


//
//
//int insertCol(int **arr, int row, int col, int key) {
//
//	int	j = key - 1;
//
//	for (int i = 0; i < row; ++i) {
//		for (int k = col; k >= j + 1; --k) {
//			arr[i][k] = arr[i][k - 1];
//
//		}
//	}
//
//
//	for (int i = 0; i < row; ++i) {
//		arr[i][j] = 0;
//	}
//
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col + 1; j++) {
//			cout << setw(10) << arr[i][j];
//		}cout << endl;
//	}
//	return 0;
//}

//void output(int**(*f)(int**, int, int, int), int **arr, int row, int col,int key) {
//
//	*f(arr, row, col,key);
//
//	for (int i = 0; i < row + 1 && **(f(arr, row, col, key) + i)>0; i++) {
//		for (int j = 0; j < col + 1 && **(f(arr, row, col, key) + i) > 0; j++) {
//			cout << setw(10) << **((f(arr, row, col, key) + j+i)) << " ";
//		}cout << endl;
//	}
//
//
//}


int menu() {

	srand(time(0));

	int row;
	int col;
	cout << "Enter size of row of array: ";
	cin >> row;
	cout << "Enter size of column of array: ";
	cin >> col;


	int** arr = new int*[row];//создаем динамический двумерный массив

	for (int i = 0; i <= row; i++) {

		arr[i] = new int[col];

	}

	

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = (rand() % 10 + 1) / int((rand() % 10 + 1));

	


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {+
			cout << setw(10) << arr[i][j];
		}cout << endl;
	}

	cout << endl << endl << endl;
	
	
	
	cout << "Choose one of this options: :" << endl << "1)Insert column\n" << "2)Insert row\n" << "3)Delete column\n" << "Delete row\n";
	int choice;
	//cin >> choice;

	cout << "Enter index of row/column: ";
	int key;
	cin >> key;

	//switch (choice) {

	//	/*case 1:

	//		insertCol(arr, row, col, key);
	//		break;
	//	}*/

		
	deleteRow(arr, row, col, key);
	/*insertRow(arr, row, col, key);
	for (int i = 0; i < row + 1; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(10) << arr[i][j];
		}cout << endl;
	}*/
	//insertRow(arr, row, col, key);
	return 0;
		
	
}


int main() {


	menu();

	system("pause");
	return 0;


}
