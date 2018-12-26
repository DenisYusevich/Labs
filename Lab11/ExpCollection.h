#pragma once
#include<iostream>
#include"Vector.h"
#include"expression.h"

using namespace std;

class ExpCollection {

private:

	
	Vector<Expression>expvec;

public:
			
	ExpCollection();

	void add(Expression exp);
	void clear();
	void calculate();
	int size();
	Expression& operator[](int index);

};



