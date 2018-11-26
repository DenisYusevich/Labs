/*Найти k-ую цифру в ряду цифр, составленных из подряд идущих натуральных чисел, начиная с 1: 12345678910111213…
Юсевич Денис 1 группа

Тесты:

Enter k: 15
2

Enter k: 11
0

Enter k: 123
6


Enter k: -5
Invalud  data

*/

#include<iostream>
#include<cmath>
#include<vector>
#include <iterator>


using namespace std;

int main() {

	int k;
	
	cout << "Enter k: ";
	cin >> k;

	if (k > 0) {
		vector<int> array1;

		for (int i = 1; i <= k; i++) {
			double i1 = i;
			double  n = log10(i1+0.5);

			if (n < 1) {


				array1.insert(array1.end(), i1);


			}
			else {

				int h = n;
				int a = i1;
				while (h >= 0) {


					array1.insert(array1.end(), a / pow(10, h));
					int c = pow(10, h);
					a = a % c;
					h = h - 1;

				}
			}

		}
		cout << array1[k - 1] << endl;
	}
	else {
		cout << "Invalud  data\n";
	}

	system("pause");
	return 0;

}






