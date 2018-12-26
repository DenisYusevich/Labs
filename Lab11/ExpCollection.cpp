#include"ExpCollection.h"
#include<iostream>

using namespace std;



ExpCollection::ExpCollection() {

	static Vector<Expression>expvec;

}


void ExpCollection::add(Expression exp) {

	expvec.push_back(exp);

}

void ExpCollection::clear() {

	if (!expvec.isEmpty()) {

		for (int i = 0; i < expvec.vec_size(); ++i) {

			expvec.pop_back();

		}
	}

}

void ExpCollection::calculate() {

	for (int i = 0; i < expvec.vec_size() - 1; ++i) {
		expvec[i].calculate();
		cout << endl;
	}

}

int ExpCollection::size() {


	return expvec.vec_size();

}

Expression& ExpCollection::operator[](int index) {

	return expvec[index];
}