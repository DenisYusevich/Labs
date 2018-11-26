/*
    Написать рекурсивную функцию для вычисления индекса максимального элемента массива из n элементов.

	3
	1 2 3 
	index:2

	4
	4 6 8 8 
	index:2

	3
	1 1 1 
	index:0


*/
#include <iostream>


using namespace std;

int findingMax(int i, int n, int maxPos, int maxN){
    if(i == n){
        return 0;
    }

    int current;
    cin >> current;
    if(current > maxN){
        maxPos = i;
        maxN = current;
    }
    findingMax(i+1, n, maxPos, maxN);
}


int main(){
    int n;
    cin >> n;
    int maxPos = 0;
    int maxN;
    cin >> maxN;
    findingMax(1, n, maxPos, maxN);
    cout << maxPos;
    system("pause");
    return 0;
}
