#pragma once

#include<iostream>
#include"expression.h"
#include"Vector.h"

using namespace std;


class Valid:public Expression {

public:

	
	void divisionBy0(int b);
	void funcOverload(Vector<char>&func);
	void noNums(Vector<Rational>&op);
	void noOperations(Vector<char>&func);
	
};