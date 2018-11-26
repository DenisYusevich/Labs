#include <iostream>
using namespace std;

class FirstClass    // базовый класс
{
protected:          // спецификатор доступа к элементу value
	int value;
public:
	FirstClass()
	{
		value = 0;
	}

	FirstClass(int input)
	{
		value = input;
	}

	void show_value()
	{
		cout << value << endl;
	}
};

class SecondClass : public FirstClass   // производный класс
{
public:
	SecondClass() : FirstClass()   // конструктор класса SecondClass вызывает конструктор класса FirstClass
	{}

	SecondClass(int inputS) : FirstClass(inputS)   // inputS передается в конструктор с параметром класса FirstClass
	{}

	void ValueSqr() // возводит value в квадрат. Без спецификатора доступа protected эта функция не могла бы изменить значение value
	{
		value *= value;
	}
};
