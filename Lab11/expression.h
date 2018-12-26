#pragma once
#include<iostream>
#include<vector>
#include"rational.h"
#include"Vector.h"


using namespace std;

class Expression:public Rational {

protected:

	Vector<char>func;

private:
	
	

public:

	string exceptionMsg;

	Rational answer;

	Vector<Rational>op;

	Expression();

	Expression(const Expression& exp);

	Expression(Vector<Rational>&r_op, Vector<char>&func);



	Rational calculate();

	Expression  operator=(const Expression &exp);

	//void print();

			

};



