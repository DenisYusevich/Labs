#include<iostream>
#include<string>
#include"Book.h"
#include"Library.h"

using namespace std;


void add(Library& lib) {

	int num;
	cout << "Enter number of books\n";
	cin >> num;
	for (int i = 0; i < num; ++i) {

		Book book;
		book.set();
		lib.push(book);

	}
	lib.shoW_back();

}

void deleteLastBook(Library& lib) {

	//if (!lib.isEmpty()) {

		lib.pop();

	//}
}

void searchName(Library lib,string name) {

	lib.searchName(name);

}

void searchAuthor(Library lib, string author) {

	lib.searchAuthor(author);

}

void searchYear(Library lib, int year) {
	lib.searchYear(year);
}

void nameSort(Library lib) {

	lib.nameSort();
	lib.show();

}

void authorSort(Library lib) {

	lib.authorSort();
	lib.show();

}

void yearSort(Library lib) {

	lib.yearSort();
	lib.show();

}

string init_s() {
	string name;
	cin >> name;
	return name;

}

int init_i() {
	int i;
	cin >> i;
	return i;
}

void show(Library lib) {

	lib.show();
}

int menu() {

	Library lib;

	int choice;

	while (true) {
		cout << "1) add to lib" << endl << "2)delete from lib" << endl
			<< "3)search name" << endl << "4)search author" << endl << "5)search year"
			<< endl << "6)sort with name(alphabet)" << "7)sort with author(alphabet)" <<
			endl << "8)sort with year" << endl <<"9)Show lib"<< "0)Exit" << endl;

		cin >> choice;
		switch (choice) {


		case 1:
			add(lib);
			break;

		case 2:
			deleteLastBook(lib);
			break;
		case 3:
			
			cout << "enter name\n";
			
			searchName(lib, init_s());
			break;
		case 4:
			
			cout << "enter author\n";
			
			searchAuthor(lib, init_s());
			break;
		case 5:
			
			cout << "Enter year\n";
			
			searchYear(lib, init_i());
			break;

		case 6:
			nameSort(lib);
			break;
		case 7:
			authorSort(lib);
			break;
		case 8:
			yearSort(lib);
			break;
		case 0:
			return 0;
		case 9:
			show(lib);
			break;

		default:
			cout << "press 0-9\n";
			break;
		}
	}


}

int main() {

	
	//Book b1("Privet", "Pushkin", 2018);
	//Book b2("Poka", "Lermontov", 1821);
	//Book b3("Privet esche raz", "Pushkin", 1835);
	//Book b4("Hello darkness", "Smbdy", 1820 );
	//Book b5("My old friend", "Me", 2018);
	//Library lib;
	//lib.push(b1);
	//lib.push(b2);
	//lib.push(b3);
	//lib.push(b4);
	//lib.push(b5);
	////lib.searchName("Hello darkness");
	//lib.show();
	//lib.nameSort();
	//cout << endl << endl;
	//lib.show();

	menu();

	
	

	system("pause");
	return 0;

}