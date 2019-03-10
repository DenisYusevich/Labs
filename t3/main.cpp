#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<fstream>
#include<string>
#include"Student.h"

using namespace std;

void show(vector<Student>data) {
	for(auto el : data) {
		cout << el << "\n";
	}
 }

int main() {

	ifstream input("input.txt");
	if (input.is_open()) {
		vector<Student>data1;
		while (!input.eof()) {
			Student temp;
			input >> temp;
			data1.push_back(temp);
		}

		cout << "ENTER AVERAGE: ";
		int rate;
		cin >> rate;
		auto res = count_if(begin(data1), end(data1), [&rate](Student stud) {return stud.getAverage() >= rate; });
		cout << "\n";
		cout << res << " students\n";
		cout << "ENTER GROUPNUMBER: ";
		int num;
		cin >> num;
		for (auto el : data1) {
			if (el.getGroup() == num)
				cout << el.getName()<<"\n";	
		}
		vector<Student>data2;
		for (auto el : data1) {
			data2.push_back(el);
		}
		cout << "\nSTANDART:\n";
		show(data2);
		cout << "\nREVERSE: \n";
		reverse(begin(data2), end(data2));
		show(data2);
		cout << "\nNAMESORT:\n";
		sort(begin(data1), end(data1), [](Student&stud1, Student&stud2) {return stud1.getName() < stud2.getName(); });
		show(data1);
		cout << "\nAVERAGESORT:\n";
		sort(begin(data1), end(data1), [](Student&stud1, Student&stud2) {return stud1.getAverage() < stud2.getAverage(); });
		show(data1);
		cout<<"\nNAME&AVERAGE SORT:\n";
		sort(begin(data1), end(data1), [](Student&stud1, Student&stud2) {if (stud1.getGroup() == stud2.getGroup())return stud1.getName() < stud2.getName(); return stud1.getGroup() < stud2.getGroup(); });
		show(data1);
	}
	system("pause");

}