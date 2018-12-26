#pragma once

#include<iostream>

using namespace std;

int gcd(int a, int b);

class Rational {


	
private:

	Rational reduce(int numer, int den) {


		int numer1 = numer;
		int den1 = den;
		numer1 /= gcd(numer, den);
		den1 /= gcd(numer, den);

		return Rational(numer1, den1);
	}

	friend Rational add(Rational a, Rational b);
	friend Rational mult(Rational a, Rational b);
	friend Rational div(Rational a, Rational b);


public:

	int numer;
	int den;


	Rational();

	Rational(int numerator, int denominator);

	Rational(const Rational &num);


	void getNum();

	void print();



	Rational operator=(Rational c);

	bool greater(Rational a, Rational b);
	

	bool less( Rational b);

	bool equal(Rational a, Rational b);

};