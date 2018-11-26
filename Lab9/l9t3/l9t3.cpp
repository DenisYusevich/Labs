#include<iostream>
#include<stack>


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

		Node<T> *temp = new Node<T>;
		temp->value = c;
		temp->prev = top;
		top = temp;
	}



	T pop() {

		if (isEmpty())
		{
			return 0;
		}
		else {
			T data = top->value;
			Node<T> *temp = top;
			top = top->prev;
			delete temp;
			return data;
		}
	}

	T topElement() {
		if (!isEmpty()) {
			return top->value;
		}
	}





	bool isEmpty()
	{
		return top ? false : true;
	}


};


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


char convertToChar(int a) {

	char A;


	char arrC[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int arrI[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 10; ++i) {
		if (a == arrI[i]) {
			A = arrC[i];
		}
		return A;
	}



}

int convertToInt(char a) {

	int A;
	

	char arrC[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int arrI[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 10; ++i) {
		if (a == arrC[i]) {
			A = arrI[i];
		}
		return A;
	}
}


char add(char a, char b) {

	int sum = convertToInt(a) + convertToInt(b);

	return convertToChar(sum);



}

char difference(char a, char b) {

	int dif = convertToInt(a) - convertToInt(b);

	return convertToChar(dif);

}


char mult(char a, char b) {

	int mult = convertToInt(a) * convertToInt(b);

	return convertToChar(mult);

}



char div(char a, char b) {

	int div = convertToInt(a)*convertToInt(b);

	return convertToChar(div);



}


int main() {

	myStack<char>num;
	myStack<char>operations;


	const char *str = "2+2*3-4";

	for (int i = 0; i < strlen(str); ++i) {

		if (isDig(str[i])) {
			num.push(str[i]);
			cout << str[i];
		}
		if (str[i] == '+' || str[i] == '-' ) {
			if (operations.isEmpty()) { operations.push(str[i]); }
			if (operations.topElement() == '-' || operations.topElement() == '+' || operations.topElement() == '*' || operations.topElement() == '/') {
				//operations.pop();
				//operations.push(str[i]);
				char a = num.pop();
				char b = num.pop();
				
				if (operations.topElement() == '+') {
					num.push(add(a, b));
					operations.pop();
					operations.push(str[i]);
					break;
				}
				if (operations.topElement() == '-') {
					num.push(difference(a, b));
					operations.pop();
					operations.push(str[i]);
					break;
				}
				if (operations.topElement() == '*') {
					num.push(mult(a, b));
					operations.pop();
					operations.push(str[i]);
					break;
				}
				if (operations.topElement() == '/') {
					num.push(div(a, b));
					operations.pop();
					operations.push(str[i]);
					break;
				}
			}
		}
		if (str[i] == '/' || str[i] == '*') {

			if (operations.isEmpty() || operations.topElement() == '+' || operations.topElement() == '-') {
				operations.push(str[i]);
			}
			if (operations.topElement() == '*' || operations.topElement() == '/') {
				//operations.pop();
				//operations.push(str[i]);
				char a = num.pop();
				char b = num.pop();
				if (operations.topElement() == '*') {
					num.push(mult(a, b));
					operations.pop();
					operations.push(str[i]);
					break;
				}
				if (operations.topElement() == '/') {
					num.push(div(a, b));
					operations.pop();
					operations.push(str[i]);
					break;
				}
			}

		}

	}

	/*char a = num.pop();
	char b = num.pop();

	if (operations.topElement() == '+') {
		num.push(add(a, b));
		operations.pop();
	}
	if (operations.topElement() == '-') {
		num.push(difference(a, b));
		operations.pop();
	}
	if (operations.topElement() == '*') {
		num.push(mult(a, b));
		operations.pop();
	}
	if (operations.topElement() == '/') {
		num.push(div(a, b));
		operations.pop();
	}*/

/*
	for (int i = 0; i < strlen(str); ++i) {
		num.push(str[i]);
	}
	for (int i = 0; i < strlen(str); ++i) {
		cout << num.pop();
	}*/


	//operations.pop();
	cout << num.pop();

	system("pause");
	return 0;



}