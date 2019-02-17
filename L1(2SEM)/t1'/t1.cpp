#include<iostream>
#include"myVector.h"
#include<string>


using namespace std;


int main() {

	Vector<char>data;
	for (char i = 'a'; i <= 'z'; ++i) {
		data.push_back(i);
	}

	for (auto i = data.begin(); i != data.end(); ++i) {
		cout << *i;
	}

	//data.show();
	cout << "\n";
	data.reverse_show();

	cout << "\n";
	auto it = Vector<char>::Iterator(data.front());


	system("pause");

}
