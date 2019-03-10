#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<fstream>

using namespace std;

void show(vector<int>data) {
	for (auto el : data) {
		cout << el << " ";
	}
}

int main() {

	ifstream input("input.txt");
	if (input.is_open()) {
		vector<int>data;
		
		while (!input.eof()){
			int val;
			input >> val;
			data.push_back(val);
		}
		show(data);
		auto it = max_element(begin(data), end(data));
		cout << *it;
		cout << "\nENTER NUMBER:\n";
		int number;
		cin >> number;
		int res = count_if(begin(data), end(data), [&number](int val) {return val == number; });
		cout << "Number:  " << res;
		cout << "\nQUANTITY OF NUMBERS HIGHER THAN 15: ";
		cout << count_if(begin(data), end(data), [](int val) {return val > 15; });
		cout << "\nQUANTITY";
		int val;
		cout << count(begin(data), end(data),0);

		//cout << "\nQUANTITY: ";   TO DO
		//cout << count_if(begin(data), end(data),[]() {});
		cout << "\nSUM: ";
		cout << accumulate(begin(data), end(data), 0);
		//AVERAGE TO DO
		

	}


	system("pause");
}
