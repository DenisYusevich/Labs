#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include"expression.h"
#include"rational.h"
#include"Vector.h"
#include"ExpCollection.h"

#include<stack>

using namespace std;

class Menu {


private:
	int yourChoice;

public:

	Menu() {

		while (yourChoice!=0) {

			choice();
		}
		
	}

	void choice();
	void input(ExpCollection &expcol);
	void calculate(ExpCollection &expcol);
	void output(ExpCollection &expcol);
	
};



