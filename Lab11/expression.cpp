#include<iostream>
#include<vector>
#include"expression.h"
#include"Vector.h"
#include"Valid.h"
#include"Log.h"
#include"exñeption.h"

using namespace std;

Expression:: Expression(Vector<Rational>&r_op,Vector<char>&func){

	this->op = r_op;
	this->func = func;
}


Expression::Expression() {

	Vector<Rational>op;

}


Rational Expression::calculate() {

	 Log log;

	if (op.vec_size() == 2) {

		try {
			
			Valid valid;
			valid.noOperations(func);
			valid.funcOverload(func);
			valid.divisionBy0(op[0].den);
			valid.divisionBy0(op[1].den);

			if (func.print_back() == '+') {

				answer = add(op[0], op[1]);
				

			}
			if (func.print_back() == '-') {

				answer = add(op[0], op[1]);

			}
			if (func.print_back() == '*') {

				answer = mult(op[0], op[1]);

			}
			if (func.print_back() == '/') {
					
				answer = div(op[0], op[1]);

			}
			answer.print();

		}
		catch (Exception ex) {
			
			cout << ex.what();
			exceptionMsg = ex.what();
			log.push(exceptionMsg);
		}
	}

	else {
		try {
			Valid valid;
			valid.noNums(op);
			valid.divisionBy0(op[0].den);
			op[0].print();
			answer = op[0];
		}

		catch (Exception ex) {
			cout << ex.what();
			exceptionMsg = ex.what();
			log.push(exceptionMsg);
		}
	}

	return answer;
}


Expression Expression:: operator=(const Expression &exp) {
	
	this->op = exp.op;
	this->func = exp.func;

	return *this;


}

Expression:: Expression(const Expression& exp) {

	op = exp.op;
	func = exp.func;


}

