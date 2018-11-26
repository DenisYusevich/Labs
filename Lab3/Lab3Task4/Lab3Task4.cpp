/*Для заданного n найти все меньшие его совершенные числа(совершенным называется число, равное сумме всех своих делителей, не равных самому числу).
Юсевич Денис 1 группа

Тесты:

Enter num: 10
Perfect num is: 6

Enter num: 30
Perfect num is: 6
Perfect num is: 28

Enter num: 10000
Perfect num is: 6
Perfect num is: 28
Perfect num is: 496
Perfect num is: 8128


Enter num: -500
Invalid data

*/

#include<iostream>

using namespace std;

int main() {

	int num;
	int sum = 0;
	int n = 1;


	cout << "Enter num: ";
	cin >> num;


	if (num > 0) {
		while (n < num) {

			n++;
			sum = 0;
			for (int i = 1; i <= n / 2; i++) {

				if (n % i == 0) {
					sum += i;

				}

			}
			if (sum == n) {
				cout << "Perfect num is: " << n << endl;
			}

		}
	}
	else {
		cout << "Invalid data\n";
	}

	system("pause");
	return 0;


}


