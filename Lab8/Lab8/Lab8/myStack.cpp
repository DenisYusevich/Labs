#include<iostream>
#include"myStack.h"

using namespace std;



Complex::Complex():re(0), im(0) {}

Complex::Complex(int re, int im) :re(re), im(im) {

}

void Complex::show() {
	cout << re << "+" << im << "i" << endl;
	cout << " abs=" << findingAbs(re, im) << endl;
}

void  Complex::getNum() {
	cin >> re >> im;

}

double  Complex::findingAbs(int re, int im) {

	complexAbs = sqrt(re * re + im * im);
	return complexAbs;

}

Complex Complex:: operator+(Complex c) const {

	int re2 = re + c.re;
	int im2 = im + c.im;


	return Complex(re2, im2);
}


Complex Complex:: operator-(Complex c) const {

	int re2 = re - c.re;
	int im2 = im - c.im;


	return Complex(re2, im2);
}


Complex Complex:: operator *(Complex c) const {

	int re2 = re * c.re - im * c.im;
	int im2 = re * c.im + c.re * im;

	return Complex(re2, im2);
}

Complex Complex:: operator /(Complex c) const {


	double re2 = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
	double im2 = (im * c.re - re * c.im) / (c.re * c.re + c.im * c.im);

	return Complex(re2, im2);
}


Complex Complex:: operator=(Complex c) {

	re = c.re;
	im = c.im;

	return Complex(re, im);



}

bool Complex::  operator >(Complex c) {

	double abs1 = findingAbs(re, im);
	double abs2 = findingAbs(c.re, c.im);

	return(abs1 > abs2) ? true : false;
}

bool Complex:: operator ==(Complex c) {

	double abs1 = findingAbs(re, im);
	double abs2 = findingAbs(c.re, c.im);

	return (abs1 == abs2) ? true : false;

}


