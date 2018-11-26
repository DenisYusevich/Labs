/*�������� � ��������� ������������������  A=(ai), i=1..n, n<=100, ����������  ����� ���������,  �����  �������� 
�������������� ���������� (��������, 22 1  36  -> 1  8 15 22 29 36).
������ ����� 1 ������

�����:

Quantity? 3
Enter nums: 22
1
36
1 8 15 22 29 36


Quantity? 5
Enter nums: 3
9
30
39
57
3 6 9 12 15 18 21 24 27 30 33 36 39 42 45 48 51 54 57


Quantity? -5
Invalid data,quantity should be higher than 1

Quantity? 3
Enter nums: 3
3
3
Invalid data,should be no duplicating numbers

*/




#include<iostream>

using namespace std;


int sum = 0;
int nod;//���
int finalQuantity;
int min;



void sort(int *arr, int size) {//������� ���������� �������

	int temp, max;
	

	for (int i = 0; i < size - 1; ++i) {

		max = i;
		for (int j = i + 1; j < size; ++j) {

			if (arr[j] > arr[max]) {

				max = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}
}

void findingNOD(int *delta,int divider,int q) {//������� ���������� ����
	int addend;

	while (divider > 0) {

		sum = 0;

		for (int i = 0; i < q - 1; ++i) {

			addend = delta[i] % divider;

			sum += addend;
		}
		if (sum > 0) {
			divider--;
		}
		if (sum == 0) {
			nod = divider;
			break;
		}
	}
}


void findingMin(int *delta,  int q) {//������� ��� ���������� ������� ������������ ��������

	int min = 0;
	for (int i = 0; i < q - 1; ++i) {

		if (delta[i] < delta[min]) {

			min = i;
		}
	}
}

int main() {


	int quantity;

	cout << "Quantity? ";
	cin >> quantity;

	if (quantity > 1) {

		int *arr = new int[quantity];//�������� ����� �������

		cout << "Enter nums: ";
		for (int i = 0; i < quantity; ++i) {

			cin >> arr[i];
		}

		sort(arr, quantity);

		int *delta = new int[quantity - 1];//�������� ��� ������ ����� �������, � ������� ����� ���������� �������� ����� ��������� ���������� �������
		for (int i = 0; i < quantity - 1; ++i) {

			delta[i] = arr[i] - arr[i + 1];
			if (delta[i] == 0) {//�������� �� ������������� �����
				cout << "Invalid data,should be no duplicating numbers\n";
				system("pause");
				return 0;
			}
		}


		findingMin(delta, quantity);//��������� ����������� ������� 

		int divider = delta[min];//����� ������ ������ ������� �� ���� �����������(�� ������� findingNOD)

		findingNOD(delta, divider, quantity);//������� ���

		finalQuantity = ((arr[0] - arr[quantity - 1]) / nod) + 1;//��������� ���������� ��������� ������� � �������������� ����������


		int *progression = new int[finalQuantity];//����� ������ ��� ����������
		progression[0] = arr[quantity - 1];
		cout << progression[0] << " ";

		for (int k = 1; k < finalQuantity; ++k) {//��������� ������ � ������� ���������� �� �����
			progression[k] = progression[k - 1] + nod;
			cout << progression[k] << " ";
		}

		cout << endl;
	}
	else {
		cout << "Invalid data,quantity should be higher than 1\n";
	}

	system("pause");
	return 0;

}//polniy spravochnik Shildta,pradt 2012//shildt 10 god ctr 23s xepom