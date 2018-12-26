#include<iostream>
#include"Valid.h"
#include"exñeption.h"

using namespace std;

void Valid::divisionBy0(int b) {

	if (b == 0) {
		throw DivByZeroErr();

	}
}

void Valid::funcOverload(Vector<char>&func) {


	if (func.vec_size() == 2) {

		throw OperationOverloadErr();

	}


}

void Valid::noNums(Vector<Rational>&op) {


	if (op.vec_size() == 0) {


		throw noNumsErr();

	}
}

void Valid::noOperations(Vector<char>&func) {

	if (func.vec_size() == 0) {

		throw NoOperations();

	}


}

