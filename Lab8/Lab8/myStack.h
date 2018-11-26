#pragma once
class Complex {

private:
	double re;
	double im;
	double complexAbs;


public:
	Complex();

	Complex(int re, int im);

	void show();
	void getNum();
	double findingAbs(int re, int im);

	Complex operator+(Complex c) const;

	Complex operator-(Complex c) const;

	Complex operator *(Complex c) const;

	Complex operator /(Complex c) const;

	Complex operator=(Complex c);

	bool  operator >(Complex c);

	bool operator ==(Complex c);

	/*ostream &  operator <<(ostream& t, const Complex& c) {
		t << c.re() << " " << c.im();
		return t;
	}
*/
	
};
