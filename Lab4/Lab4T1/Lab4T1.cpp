/*��� ������ ����� �����, � ������� ��� ����� ����� ������ ����������� ������ ���������� ���,
���� ����� ����������� �������� ���������� ���. ����� ��� �����.
������ ����� 1 ������

�����:

Enter quantity of numbers: 9
Enter numbers: 5
3
5
3
5
2
2
4
4

Odd is: 5

Enter quantity of numbers: 5
Enter numbers: 2
2
3
1
1

Odd is: 3




*/



#include<iostream>

using namespace std;

int main() {

	int size;

	cout << "Enter quantity of numbers: ";
	cin >> size;

	int counter = 1;

	int *arr = new int[size];//������� ������������ ������

	cout << "Enter numbers: ";
	

	for (int i = 0; i < size; ++i) {//��������� ������ ����������

		cin >> arr[i];

	}

	for (int i = 0; i < size; ++i) {/*����������� �� �������, ����� ������� ����� �� �����, ����������� �������,
											���� �� �������� ������ ����������,�������� ��� �������� �������,����� ������� 
											��������� �������� ���� ������� �������, ������������� �������� ���-�� ���*/


		counter = 1;

		for (int k = i + 1; k < size; ++k) {
			
			if (arr[i] == arr[k]) {

				counter++;
				if (counter % 2 == 0) {

					arr[k] = 0;
					arr[i] = 0;

				}	
			}
		}
	}


	for (int i = 0; i < size; ++i) {

		if (arr[i] != 0) {
			cout << "\n";
			cout << "Odd is: " << arr[i] << endl;;
		}
	}
	system("pause");
	return 0;

}