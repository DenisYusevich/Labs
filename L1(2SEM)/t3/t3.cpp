#include<iostream>
#include<list>
#include<vector>
#include<deque>
#include<array>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include<numeric>
#include<fstream>
#include<string>

using namespace std;

int main() {

	list<int>_list;
	vector<int>_vector;
	deque<int>_deque;
	array<int,5> _array;
	stack<int>_stack;
	queue<int>_queue;
	


	ifstream input("input.txt");
	int value;

	while (!input.eof()) {
		input >> value;
		_list.push_back(value);
		
	}

	for (auto element : _list) {
		cout << element << " ";
	}
	cout << endl;

	cout << "Number of values equal to 1:\n";
	cout << count_if(_list.begin(), _list.end(), [](int a) {return a == 1; });
	cout << "\n";
	cout << "Number of values higher than 5:\n";
	cout << count_if(_list.begin(), _list.end(), [](int a) {return a >5; });
	cout << "\n";
	cout << "Number of values:\n";
	cout << count_if(_list.begin(), _list.end(), [](auto val) {return typeid(val) == typeid(int); });
	cout << "\n";
	cout << "Sum of values:\n";
	cout << accumulate(_list.begin(), _list.end(), 0);
	cout << "\n";
	cout << "Average:\n";
	cout<< accumulate(_list.begin(), _list.end(), 0) / count_if(_list.begin(), _list.end(), [](auto val) {return typeid(val) == typeid(int); });
	cout << "\n";

	system("pause");

}