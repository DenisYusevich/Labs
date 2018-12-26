#include<iostream>
#include"rational.h"
using namespace std;


int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}



Rational ::Rational() :numer(0), den(0) {}

Rational:: Rational(int numerator, int denominator) :numer(numerator), den(denominator) {

}

Rational::Rational(const Rational &num) {

	numer = num.numer;
	den = num.den;

}


void Rational:: getNum() {
	cin >> numer >> den;
}

void Rational:: print() {
	cout << numer << "/" << den;

}



Rational Rational:: operator=(Rational c) {

	numer = c.numer;
	den = c.den;

	return reduce(numer, den);
}

bool Rational:: greater(Rational a, Rational b) {
	if (a.den != b.den) {
		a.numer *= b.den;
		b.numer *= a.den;
	}
	return (a.numer > b.numer) ? true : false;
}

bool Rational:: less( Rational b) {
	if (this->den != b.den) {
		this->numer *= b.den;
		b.numer *= this->den;
	}
	return (this->numer < b.numer) ? true : false;
}

bool Rational:: equal(Rational a, Rational b) {
	if (a.numer == b.numer && a.den == b.den) {
		return true;
	}
	else {
		return false;
	}
}


Rational  add(Rational a, Rational b) {


	int numer2 = (a.numer * b.den) + (b.numer * a.den);
	int den2 = a.den * b.den;
	Rational c(numer2, den2);

	return c.reduce(numer2, den2);

}

Rational  mult(Rational a, Rational b) {
	int numer2 = a.numer * b.numer;
	int den2 = a.den * b.den;
	Rational c(numer2, den2);

	return c.reduce(numer2, den2);
}
Rational  div(Rational a, Rational b) {
	int numer2 = a.numer * b.den;
	int den2 = b.numer * a.den;
	Rational c(numer2, den2);

	return c.reduce(numer2, den2);
}





