#include<iostream>
#include"ForwardList.h"

using namespace std;

int main() {

	Arr<int>_arr;

	_arr.push_back(7);
	_arr.push_back(4);
	_arr.push_back(10);
	_arr.push_front(1);
	_arr.show();
	cout << "\n";
	cout << _arr[2];


	system("pause");

}