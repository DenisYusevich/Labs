/*Ќапечатать в пор€дке возрастани€ все простые несократимые дроби, заключенные между 0 и 1, знаменатели которых меньше заданного числа n.
ёсевич ƒенис 1 группа

“есты:

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
double s = 1;//сумма элементов массива






int main() {

	double i1, j1;
	
	

	cout << "Enter num: ";
	cin >> num;

	if (num <= 0) {//выходим, если введенное число не положительно

		cout << "Invalid data \n";
		system("pause");
		return 0;
	}

	double** division = new double*[num];//создаем динамический двумерный массив

	for (int p = 0; p < num; p++) {

		division[p] = new double[num];

	}
	
	


	for (int i = 2; i < num; i++) {//массив заполн€ем результатами делени€ наших дробей,в это же врем€ индексы и будут €вл€тьс€  числителем и знаменателем
		i1 = i;
		for (int j = 1; j < i; j++) {
			j1 = j;
			division[i][j] = j1 / i1;
			
			
		}

	}


	//дальнейший  цикл for просто показывают как работает программа нагл€дно(выводит массив в виде таблицы с помощью setw)
	for (int i = 2; i < num; i++) {
		for (int j = 1; j < i; j++) {
			cout << setw(10) << division[i][j];
		}cout << endl;
	}
	cout << endl; cout << endl;
	for (int i = 2; i < num; i++) {//пробегаемс€ по элементам массива, если находим совпадающие значени€,то обнул€ем(таким образом мы избавл€емс€ от сократимых дробей)
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


	for (int i = 2; i < num; i++) {//выводим массив с обнуленными значени€ми(оп€ть просто дл€ нагл€дности)
		for (int j = 1; j < i; j++) {

			cout << setw(10) << division[i][j];
		}cout << endl;
	}
	cout << endl << endl;


	double min = 1; int raw = 1; int column = 1; 
	while (s > 0)//выводим элементы массива по возрастанию(находим максимальный - обнул€ем, и так до тех пор пока сумма всех элементов массива не станет равна нулю
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
		cout << column << "/" << raw << "   ";//выводим нужные нам дроби
		
		for (int l = 2; l < num; l++) {//цикл считающий сумму элементов массива
			for (int m = 1; m < l; m++) {
				s = s + division[l][m];
			}
		}
	} 
	system("pause");
	return 0;

}