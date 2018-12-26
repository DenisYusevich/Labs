#pragma once
#include<string.h>
#include<iostream>
#include<string>


using namespace std;

class Exception {


public:

	Exception() {
		cout << "Exception has occured!\n";
	};

	string what() {

		return  msg;
	}

protected:

	string msg;

};


class DivByZeroErr :public Exception {


private:

	


public:


	DivByZeroErr() {
		msg = "Division by zero!\n";
		
	}

};


class InputError :public Exception {

private:




public:

	InputError() {

		msg = "File can't be opened!";
	}

};


class EmptyError:public Exception {


private:

public:




	
};



class OperationOverloadErr :public Exception {

private:

public:


	OperationOverloadErr() {


		msg = "Too much operations!\n";


	}
};


class noNumsErr:public Exception {


private:

public:


	noNumsErr() {

		msg = "No numbers in this line\n";

	}
};

class NoOperations :public Exception {


private:


public:

	NoOperations() {
		msg = "No operations in line\n";

	}

};
