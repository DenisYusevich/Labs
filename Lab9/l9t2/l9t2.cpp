#include<iostream>
#include<string>
#include <cstdlib>


using namespace std;


template<class T>
class Node {

public:

	T value;
	Node* prev;

};



template<class T>
class myStack {

private:
	Node<T>* top;


public:
	void push(T c) {

		Node<T> *pv = new Node<T>;
		pv->value = c;
		pv->prev = top;
		top = pv;
	}



	T pop() {

		if (isEmpty())
		{
			return 0;
		}
		else {
			T temp = top->value;
			Node<T> *pv = top;
			top = top->prev;
			delete pv;
			return temp;
		}
	}





	bool isEmpty()
	{
		return top ? false : true;
	}


};


char max(int a, int b) {

	/*int A;
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
	}*/

	return a > b ? a : b;


}

char min(char a, char b) {

	/*int A = 0;
	int B = 0;

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
	else if (A > B) {
		return b;
	}
	else {
		return 'e';
	}*/

	return a < b ? a : b;

}

//bool isDig(char x) {
//
//	bool flag = false;
//
//	char arr[10] = { '0','1','2','3','4','5','6','7','8','9' };
//	for (int i = 0; i < 10; ++i) {
//		if (x == arr[i]) {
//			flag = true;
//		}
//	}
//
//	if (flag == true) {
//		return true;
//	}
//	else {
//		return false;
//	}
//
//}


int main() {


	string s;
	cin >> s;
	myStack<int> num;
	myStack<char> op;

	int i = 0;

	while (s[i]) {
		
		if (s[i] == 'a' || s[i] == 'i') {
			op.push(s[i]);
			i += 2;
		}
		else if (isdigit(s[i]) || s[i] == '-') {
			num.push(s[i] - '0');
			while (isdigit(s[i]) || s[i] == '-') i++;
		}
		else if (s[i] == ')') {
			int operand1, operand2, operation;
			operation = op.pop();
			operand2 = num.pop();
			operand1 = num.pop();
			switch (operation) {
			case 'a':
				num.push(max(operand1, operand2));
				break;
			case 'i':
				num.push(min(operand1, operand2));
				break;
			}
			i++;
		}
		else
			if (s[i] == '(' || s[i] == ' ' || s[i] == ',' || s[i] == 'm') i++;
	}
	cout << num.pop() << "\n";
	system("pause");
	return 0;
}
