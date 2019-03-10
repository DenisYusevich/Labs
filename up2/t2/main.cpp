#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<fstream>
#include<string>
#include<set>
#include<map>

using namespace std;

void show(vector<string>data) {
	for (auto el : data) {
		cout << el << " ";
	}
}


int main() {
	ifstream input("input.txt");
	if (input.is_open()) {
		vector<string>data;

		while (!input.eof()) {
			string str;
			input >> str;
			data.push_back(str);
		}

		show(data);
		cout << "\n";
		sort(begin(data), end(data));
		show(data);
		cout << "\n";
		for (auto el : data) {
			if (el[0] == 'h')
				cout << el;
		}
		cout << "\n";
		for (auto it = begin(data); it!=end(data);) {
			if (it->at(0) == 'h') {
				it = data.erase(it);
			}
			else {
				++it;
			}
			
		}
		show(data);

		set<string>_set;
		for (auto el : data) {
			_set.emplace(el);
		}
		cout << "\nSET ELEMENTS: ";
		for(auto el:_set){
			cout << el<<" ";
		}
		cout << "\n\n";
		map<string, int>_map;
		for (auto curr_el : data) {
			int num = count_if(begin(data), end(data), [&curr_el](auto element) {return element == curr_el; });
			_map.emplace(curr_el, num);
		}
		for (auto el : _map) {
			cout << el.first << ":" << el.second << "\n";
		}



	}
	system("pause");
}