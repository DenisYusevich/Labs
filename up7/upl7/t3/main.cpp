#include<iostream>
#include<string>
#include"Book.h"
#include"Library.h"

using namespace std;


int main() {

	
	Book b1("Privet", "Pushkin",  1820);
	Book b2("Ya ochen' krutoi", "Lermontov", 1821);
	Book b3("I snova Ya", "Pushkin", 1821);
	Book b4("Fuck u no GG", "PartinG", 2018);
	Book b5("Fuck it all", "Me", 2018);

	Library lib;

	lib.push(b1);
	lib.push(b2);
	lib.push(b3);
	lib.push(b4);
	lib.push(b5);

	lib.searchName("Fuck u no GG");

	system("pause");
	return 0;

}