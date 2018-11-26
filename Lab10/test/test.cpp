#include <iostream>
using namespace std;

class FirstClass    // ������� �����
{
protected:          // ������������ ������� � �������� value
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

class SecondClass : public FirstClass   // ����������� �����
{
public:
	SecondClass() : FirstClass()   // ����������� ������ SecondClass �������� ����������� ������ FirstClass
	{}

	SecondClass(int inputS) : FirstClass(inputS)   // inputS ���������� � ����������� � ���������� ������ FirstClass
	{}

	void ValueSqr() // �������� value � �������. ��� ������������� ������� protected ��� ������� �� ����� �� �������� �������� value
	{
		value *= value;
	}
};
