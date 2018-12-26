#include"menu.h"
#include"exñeption.h"
#include"rational.h"
#include"expression.h"
#include"Vector.h"
#include"Parser.h"
#include"ExpCollection.h"
#include"Log.h"
#include<Windows.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Menu::choice() {
	cout << "Choose one of this options:\n1)input from a file\n"
		"2)calculate\n3)output to a file\n0)Exit";


	cin >> yourChoice;

	static ExpCollection expcol;

	switch (yourChoice) {


	case 1:
		input(expcol);
		
		break;
	case 2:
		calculate(expcol);
		break;
	case 3:
		output(expcol);
		break;
	case 0:
		return;
		break;
	}

}


void  Menu::input(ExpCollection &expcol) {

	 Log log;
	 

	bool isOpen = false;
	string name;
	ifstream input;
	while (isOpen == false) {
		
		cout << "Enter name of the file(don't forget about .txt):";
		cin >> name;
		
		try {
			input.open(name);
			if (!input.is_open()) {throw InputError(); }
			else {
				log.push(name+" was opened\n");
				isOpen = true;
			}
		}
		catch (Exception ex) {
			cout << ex.what();
			log.push(ex.what() + "Name of file: " + name + "\n");
		}
		
	}
	string str;
	

	while (!input.eof()) {
	

		
		getline(input, str);
		cout << str << "\n";
		Parser parser(str);
		str.clear();
		expcol.add(parser.createExp());

	}

}



void Menu::calculate(ExpCollection &expcol) {

	expcol.calculate();
}



void Menu::output(ExpCollection &expcol) {
	
	ofstream out("output.txt");

	
	for (int i = 0; i < expcol.size(); ++i) {

		if (expcol[i].answer.numer != 0 && expcol[i].answer.den != 0)
		out << expcol[i].answer.numer << "/" << expcol[i].answer.den << "\n";

		else {
			out << expcol[i].exceptionMsg << "\n";
		}
	}
}




