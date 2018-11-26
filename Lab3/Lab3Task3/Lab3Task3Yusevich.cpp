/*���������� � ������� ����������� ��� ������� ������������ �����, ����������� ����� 0 � 1, ����������� ������� ������ ��������� ����� n.
������ ����� 1 ������

�����:

Enter num: 6
1/5   1/4   1/3   2/5   1/2   3/5   2/3   3/4   4/5

Enter num: 10
1/9   1/8   1/7   1/6   1/5   2/9   1/4   2/7   1/3   3/8   2/5   3/7   4/9   1/2  
5/9   4/7   3/5   5/8   2/3   5/7   3/4   7/9   4/5   5/6   6/7   7/8   8/9


Enter num: -5
Invalid data


*/


#include<iostream>
#include <iomanip>

using namespace std;


int num;
double s = 1;//����� ��������� �������






int main() {

	double i1, j1;
	
	

	cout << "Enter num: ";
	cin >> num;

	if (num <= 0) {//�������, ���� ��������� ����� �� ������������

		cout << "Invalid data \n";
		system("pause");
		return 0;
	}

	double** division = new double*[num];//������� ������������ ��������� ������

	for (int p = 0; p < num; p++) {

		division[p] = new double[num];

	}
	
	


	for (int i = 2; i < num; i++) {//������ ��������� ������������ ������� ����� ������,� ��� �� ����� ������� � ����� ��������  ���������� � ������������
		i1 = i;
		for (int j = 1; j < i; j++) {
			j1 = j;
			division[i][j] = j1 / i1;
			
			
		}

	}


	//����������  ���� for ������ ���������� ��� �������� ��������� ��������(������� ������ � ���� ������� � ������� setw)
	for (int i = 2; i < num; i++) {
		for (int j = 1; j < i; j++) {
			cout << setw(10) << division[i][j];
		}cout << endl;
	}
	cout << endl; cout << endl;
	for (int i = 2; i < num; i++) {//����������� �� ��������� �������, ���� ������� ����������� ��������,�� ��������(����� ������� �� ����������� �� ���������� ������)
		for (int j = 1; j < i; j++) {
			if (division[i][j] != 0)
			{
				for (int l = i+1; l < num; l++) {
					for (int m = j+1; m < l; m++) {
						if (division[l][m] == division[i][j])
						{
							division[l][m] = 0;

						}
					}

				}

			}
		}
	}


	for (int i = 2; i < num; i++) {//������� ������ � ����������� ����������(����� ������ ��� �����������)
		for (int j = 1; j < i; j++) {

			cout << setw(10) << division[i][j];
		}cout << endl;
	}
	cout << endl << endl;


	double min = 1; int raw = 1; int column = 1; 
	while (s > 0)//������� �������� ������� �� �����������(������� ������������ - ��������, � ��� �� ��� ��� ���� ����� ���� ��������� ������� �� ������ ����� ����
	{
		s = 0;
		min = 1;
		
		for (int i = 2; i < num; i++) {
			for (int j = 1; j < i; j++) {

				if (division[i][j] < min && division[i][j] != 0) {

					min = division[i][j]; raw = i; column = j;
					
				}
			}
		}
		division[raw][column] = 0;
		cout << column << "/" << raw << "   ";//������� ������ ��� �����
		
		for (int l = 2; l < num; l++) {//���� ��������� ����� ��������� �������
			for (int m = 1; m < l; m++) {
				s = s + division[l][m];
			}
		}
	} 
	system("pause");
	return 0;

}