#pragma once
#include<iostream>
#include"Vector.h"
#include<string.h>
#include"rational.h"
#include"expression.h"

using namespace std;


class Parser {

private:

	string str;
	Vector<int>op;
	Vector<char>func;
	Vector<Rational>fraction;

public:

	Parser(string str)  {
		this->str = str;
	};

	Expression createExp();
	
};