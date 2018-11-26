/*Заполнить квадратную матрицу (n x n) натуральными четными числами 2,4,6,8,... по сходящейся к центру линии ( по спирали).
Юсевич Денис 1 группа

Тесты:

 0    2    4    6    8
   30   32   34   36   10
   28   46   48   38   12
   26   44   42   40   14
   24   22   20   18   16


	0    2    4    6    8   10   12   14   16   18
   70   72   74   76   78   80   82   84   86   20
   68  126  128  130  132  134  136  138   88   22
   66  124  166  168  170  172  174  140   90   24
   64  122  164  190  192  194  176  142   92   26
   62  120  162  188  198  196  178  144   94   28
   60  118  160  186  184  182  180  146   96   30
   58  116  158  156  154  152  150  148   98   32
   56  114  112  110  108  106  104  102  100   34
   54   52   50   48   46   44   42   40   38   36




*/


#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	const int N = 10;
	int counter = 1;

	int matrix[N][N];


	
	int n = N;
	int j = 0;
	int i = 0;

	matrix[0][0] = 0;

	while (counter < N * N) {

		for (int step = 1; step <= 4; ++step) {

			if (step == 1) {
				while (j <= n - 2 && matrix[i][j + 1] < 0) {
					matrix[i][j + 1] = matrix[i][j] + 2;
					j = j + 1;
					counter = counter + 1;
				}
			}
			if (step == 2) {
				while (i <= n - 2 && matrix[i + 1][j] < 0) {
					matrix[i + 1][j] = matrix[i][j] + 2;
					i = i + 1;
					counter = counter + 1;
				}
			}

			if (step == 3) {
				while (j >= 1 && matrix[i][j - 1] < 0) {
					matrix[i][j - 1] = matrix[i][j] + 2;
					j = j - 1;
					counter = counter + 1;
				}
			}
			if (step == 4) {
				while (matrix[i - 1][j] < 0 && i >= 2) {
					matrix[i - 1][j] = matrix[i][j] + 2;
					i = i - 1;
					counter = counter + 1;

				}
			}
		}

	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << setw(5) << matrix[i][j];
		}

		cout << endl;
	}

	cout << "...." << endl;
	cout << matrix[11][11] << " ";

	cout << endl;
	system("pause");
	return 0;
	
}
