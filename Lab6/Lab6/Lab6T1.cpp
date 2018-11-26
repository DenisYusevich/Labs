#include<iostream>//esli podstroka to odnoznachno i podmnozhestvo
//ряд фарея (3 лаба бой)

using namespace std;

bool exitt = false;

double adding(double a, double b) {
	return a + b;
}

double substruction(double a, double b) {
	return a - b;

}

double mult(double a, double b) {
	return a * b;
}


double division(double a, double b) {
	return a / b;
}

double calculate(double(*f)(double, double), double a,double b) {
	
	return f(a, b);


}


int menu() {

	int a, b;

	double(*pAdding)(double, double);
	pAdding = adding;
	double(*pSubstruction)(double, double);
	pSubstruction = substruction;
	double(*pMult)(double, double);
	pMult = mult;
	double(*pDivision)(double, double);
	pDivision = division;

	
	cout << "Enter two nums boi: ";
	cin >> a >> b;

	cout << "Choose one of these options: " << endl << "1)Adding" << endl << "2)Substruction" << endl << "3)Multiplication" << endl << "4)Division" << endl << "0)Exit\n";
	int choice;
	cin >> choice;

	switch (choice) {
	case 1:cout << calculate(pAdding, a, b) << endl;
		break;

	case 2:cout << calculate(pSubstruction, a, b);
		break;
	case 3:cout << calculate(pMult, a, b);
		break;
	case 4:cout << calculate(pDivision, a, b);
		break;
	case 0:exitt = true;
		return 0;
		break;

	}
	
	return 0;

}


int main() {
	
	
	while (exitt == false) {
		menu();
	}


		system("pause");
		return 0;
}
