#include<iostream>
#include"Vector.h"
using namespace std;

int main() {

	Vector<int>data;

	for (int i = 0; i < 10; ++i) {
		data.push_back(i);
	}
	data.show();
	cout << "\n";
	data.push_front(5);

	data.show();

	system("pause");

}
