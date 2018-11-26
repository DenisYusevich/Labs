#include<iostream>
#include<cmath>


using namespace std;


int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}


class Rational {

private:
	int numer;
	int den;

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

	

	Rational() :numer(0), den(0) {}

	Rational(int numerator, int denominator) :numer(numerator), den(denominator) {

	}

	Rational(const Rational &num) {

		numer = num.numer;
		den = num.den;

	}


	void getNum() {
		cin >> numer >> den;
	}

	void print() {
		cout << numer << "/" << den;

	}

	Rational add(Rational a, Rational b);
	Rational mult(Rational a, Rational b);
	Rational div(Rational a, Rational b);
	

	Rational operator=(Rational c) {

		numer = c.numer;
		den = c.den;

		return reduce(numer, den);
	}

	bool greater(Rational a,Rational b) {
		if (a.den != b.den) {
			a.numer *= b.den;
			b.numer *= a.den;
		}
		return (a.numer > b.numer) ? true : false;
	}

	bool less(Rational a, Rational b) {
		if (a.den != b.den) {
			a.numer *= b.den;
			b.numer *= a.den;
		}
		return (a.numer < b.numer) ? true : false;
	}
	
	bool equal(Rational a, Rational b) {
		if (a.numer == b.numer && a.den == b.den) {
			return true;
		}
		else {
			return false;
		}
	}


};

Rational add(Rational a, Rational b) {


		int numer2 = (a.numer * b.den) + (b.numer * a.den);
		int den2 = a.den * b.den;
		Rational c(numer2, den2);
	
		return c.reduce(numer2, den2);

}

Rational mult(Rational a, Rational b) {
	int numer2 = a.numer * b.numer;
	int den2 = a.den * b.den;
	Rational c(numer2, den2);

	return c.reduce(numer2, den2);
}
Rational div(Rational a, Rational b) {
	int numer2 = a.numer * b.den;
	int den2 = b.numer * a.den;
	Rational c(numer2, den2);

	return c.reduce(numer2, den2);
}



template <class T>
class Queue {

public:
	Queue() :first(NULL), last(NULL) {
		
	}
	~Queue() {
		
		while (!isEmpty()) {
			pop();
		}
		isEmpty();
	}

	void push(const T& object);
	T pop();
	const T& topElement();
	bool isEmpty();

private:
	struct QueueNode {
		T value;
		QueueNode *next;

		QueueNode(const T& newData, QueueNode *nextNode)
			: value(newData), next(nextNode) {}
	};

	Queue(const Queue& lhs) {}
	QueueNode *first;
	QueueNode *last;

};

template <class T>
void Queue<T>::push(const T& obj) {
	
	QueueNode *temp = new QueueNode(obj, NULL);
	if (first != NULL) {
		last->next = temp;
		last = temp;
	}
	else first = last = temp;
}

template <class T>
T Queue<T>::pop() {
	
	if (!isEmpty()) {
		T data = first->value;
		first = first->next;
		return data;
	}
}

template <class T>
const T& Queue<T>::topElement() {
	
	if (!isEmpty()) {
		return first->value;
	}
}

template <class T>
bool Queue<T>::isEmpty() {
	if (first == NULL) {
		return true;
	}
	else {
		return false;
	}
}


int main() {


	Rational r1(3, 5);
	Rational r2(2, 10);
	Rational r3;
	//r3 = r1.add(r1, r2);
	
	r3 = add(r1, r2);
	r3.print();
	cout << endl;

	Queue<Rational>qq;
	Rational r4;
	qq.push(r1);
	qq.push(r2);
	qq.push(r3);
	r4 = qq.topElement();
	r4.print();

	system("pause");
	return 0;




}
