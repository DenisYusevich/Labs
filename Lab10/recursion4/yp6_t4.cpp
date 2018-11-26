/*
Написать рекурсивную функцию для вычисления значения
так называемой функции Аккермана для неотрицательных чисел n и m.

    3 3
	61

	2 2
	7

	4 4
	(не считает тк слишком глубокая рекурсия)


*/

#include <iostream>


using namespace std;

unsigned long long accerman(int m, int n){
    if(m==0){
        return n+1;
    }
    if(m > 0 && n ==0){
        return accerman(m-1, 1);
    }
    if(m > 0 && n > 0){
        return accerman(m-1, accerman(m, n-1));
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << accerman(m, n)<<"\n";
    system("pause");
    return 0;
}
