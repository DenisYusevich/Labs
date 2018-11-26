#pragma once
#include"Book.h"
#include<string.h>
#include<iterator>
#include<vector>
using namespace std;


class Book {

public:

	string name;
	string author;
	int year;
	Book* next;

	Book() {
		name = NAN;
		author = NAN;
		year = 0;
	}
	Book(string name, string author, int year) :name(name), author(author),
		year(year) {};

	Book(string name, string author, int year,Book* next) :name(name), author(author),
		year(year) ,next(next) {};

	void show();
	
};



class Library :public Book {

private:
	
	vector<Book>vv;



public:

	Library() {
		vector<Book>vv;
	}

	void push(Book book);
	void pop();
	bool isEmpty();
	void searchName(string name);
	void searchAuthor(string author);
	void searchYear(int year);
	void yearSort(int year);
	


};

	/*void push(Book book);
	void pop();
	void show();
	Book first();
	Book last();
	void searchName(string name,Library lib);
	void searchAuthor(string author);
	void searchYear(int year);
	typedef Book iterator;*/
		
//void Library::push(Book book) {
//
//	tail = new Book(name, author, year, tail);
//
//}
//
//void Library::pop() {
//
//	Book* temp = tail;
//	tail = tail->next;
//	name = next->name;
//	author = next->author;
//	year = next->year;
//	delete temp;
//
//}
//
//void Library::show() {
//
//	cout << name << " " << author << " " << year << endl;
//
//}
//
//Book Library::first() {
//	return *head;
//}
//
//Book Library::last() {
//	return *tail;
//}
//
//void Library::searchName(string name,Library lib) {
//
//	Library::iterator i = lib.first(); i != lib.last();
//
//
//}


void Library::push(Book book) {
	vv.push_back(book);
}

void Library::pop() {
	vv.pop_back();

}

bool Library:: isEmpty() {
	return vv.empty() ? true : false;
}


void Book::show() {
	cout << name << " " << author << " " << year << endl;
	}



void Library::searchName(string name) {

	for (int i = 0; i < vv.size(); ++i) {
		if (name == vv[i].name) {
			vv[i].show();
		}
	}
}

void Library::searchAuthor(string author) {

	for (int i = 0; i < vv.size(); ++i) {
		if (author == vv[i].author) {
			vv[i].show();
		}
	}
}

void Library::searchYear(int year) {

	for (int i = 0; i < vv.size(); ++i) {
		if (year == vv[i].year) {
			vv[i].show();
		}
	}
}

void Library::yearSort(int year) {

	


}
