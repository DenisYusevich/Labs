/*����� ��� ����������� �����, �� ������������� ��������� ����� n, � ������� ��� ����� � ������ ����� ��������
������ ����� 1 ������

�����:

Enter num: 150
Quantity: 123

Enter num: 25
Quantity: 23


Enter num: -150
Invalid data



*/

#include<iostream>

using namespace std;

                                     
int quantity = 0;
int num;

int n = 0;
int sum = 0;
int lowerNumbers = 0;//���������� ����� ������� ������ ��������� � ����� ���� ��������������� ����� � ������



bool isUnique(int n) {//�������, ����������� ����� �� ������������� ���� � ������

	quantity = 0;
	sum = 0;
	int digits[10] = { 0 };

	while (n > 0) {
		digits[n % 10]++;
		n /= 10;
		quantity++;
	}

	for (int i = 0; i < 10; i++) {
		if (digits[i] > 0) {
			sum++;
		}
	}
	
	if (quantity == sum) {
		return true;
	}
}

int main() {

	
	cout << "Enter num: ";
	cin >> num;

	if (num > 0) {

		while (n < num) {
			n++;
			if (isUnique(n) == true) {
				lowerNumbers++;
				//cout << n << endl;    //����� ������� ���� ����� � ���������������� �������,���� ��� ���������

			}
		}
		cout << "Quantity: " << lowerNumbers << endl;
	}
	else {
		cout << "Invalid data\n";
	}
	system("pause");
	return 0;
	
}


