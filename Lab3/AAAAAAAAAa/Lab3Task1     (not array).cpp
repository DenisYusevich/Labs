/*����� ���������� ��������� ���� � ������ ��������� ������������ ����� n (����������� ��������� � �������������� � ��� ������������� ��������).
������ ����� 1 ������

�����:


Enter num: 511
2

Enter num: 3389663
4


Enter num: -10
Invalid  data

*/

#include<iostream>

using namespace std;

int main() {


	int n;
	cout << "Enter num: ";
	cin >> n;

	int currentLastDigit;
	int counter = 0;
	int currentN;
	
	if (n > 0) {
		for (int i = 0; i <= 9; ++i) {//��������� ��� ����� ����� �� ���������� � i, ���� �������� ������� ������� �� while � ����������,� counter ����������� �����
			currentN = n;
			while (currentN > 0) {

				currentLastDigit = currentN % 10;
				if (currentLastDigit == i) {
					counter++;
					break;
				}
				currentN /= 10;
			}
		}
		cout << counter << endl;
	}
	else {
		cout << "Invalid  data\n";
	}

 system("pause");
 return 0;
}