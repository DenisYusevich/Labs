#include<iostream>
#include<stack>


using namespace std;


char max(char a, char b) {

	int A;
	int B;

	char arrC[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int arrI[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 10; ++i) {
		if (a == arrC[i]) {
			A = arrI[i];
			cout << "A:" << A;
		}
		if (b == arrC[i]) {
			B = arrI[i];
			cout << "B:" << B;
		}
	}

	if (A > B) {
		return a;
	}
	if (A < B) {
		return b;
	}


}

char min(char a, char b) {

	int A;
	int B;

	char arrC[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int arrI[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 10; ++i) {
		if (a == arrC[i]) {
			A = arrI[i];
		}
		if (b == arrC[i]) {
			B = arrI[i];
		}
	}

	if (A < B) {
		return a;
	}
	if (A > B) {
		return b;
	}


}

bool isDig(char x) {

	bool flag = false;

	char arr[10] = { '0','1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 10; ++i) {
		if (x == arr[i]) {
			flag = true;
		}
	}

	if (flag == true) {
		return true;
	}
	else {
		return false;
	}

}


int main() {


	stack<char>Operand;
	stack<char>Function;

	char c[] = "8 или min(4, min(3, 5)) или  min(min(3, 5), min(2, min(3, 4)))";

	//char c[] = "max(3,6)";

	int counter = 0;
	char a;
	char b;

	for (int i = 0; i < strlen(c)+1; ++i) {

		if (isDig(c[i]) == true) {
			Operand.push(c[i]);
		}
		if (c[i] == 'x' || c[i] == 'n') {
			Function.push(c[i]);

		}
			
		if (c[i] == ')') {

		

			if (Function.top() == 'x') {

				a = Operand.top();
				cout << a;
				Operand.pop();
				b = Operand.top();
				cout << b;
				Operand.pop();
				Operand.push(max(a, b));
				cout << Operand.top();
				Function.pop();

			}

			if (Function.top() == 'n') {

				a = Operand.top();
				Operand.pop();
				b = Operand.top();
				Operand.pop();
				Operand.push(min(a, b));
				//cout << Operand.top();
				Function.pop();

			}
				
		}
		
	}

	cout << Operand.top()<<endl;
	Operand.pop();
	cout << Operand.top() << endl;
	Operand.pop();
	cout << Operand.top();

	system("pause");
	return 0;
}