#include<iostream>
#include<fstream>
#include<list>
#include<algorithm>
#include<string>



using namespace std;

void show(list<string>&l) {
	for (auto element : l) {
		cout << element << " ";
	}
	cout<<"\n";
}



int main() {

	list<string>myList;
	ifstream  input("input.txt");

	string str;

	while (!input.eof()) {
		getline(input, str);
		myList.push_back(str);
		str.clear();
	}
	show(myList);
	myList.sort();
	show(myList);
	
	list<string>::iterator it1 = find_if(myList.begin(), myList.end(), [](string el) {return el[0] == 'h'; });
	for (auto element : myList) {
		if (element == *it1)
			cout << element;
	}
	cout << "\n";
	myList.erase(it1);
	show(myList);
	system("pause");
}