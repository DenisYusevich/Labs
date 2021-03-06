#include<iostream>
#include"myStack.h"



using namespace std;





template <class T>
class Stack {
public:
	Stack() :top(0) {
		cout << " Stack constructor\n";
	}
	~Stack() {
		cout << " Stack destructor\n";
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
	struct StackNode {
		T data;                     
		StackNode *next;           

		
		StackNode(const T& newData, StackNode *nextNode)
			: data(newData), next(nextNode) {}
	};

	Stack(const Stack& lhs) {}
	StackNode *top;                 
};

template <class T>
void Stack<T>::push(const T& obj) {
	cout << " PUSH \n";
	top = new StackNode(obj, top);
}

template <class T>
T Stack<T>::pop() {
	cout << " POP \n";
	if (!isEmpty()) {
		StackNode *topNode = top;
		top = top->next;
		T data = topNode->data;
		delete topNode;
		return data;
	}
	//return 0;
}

template <class T>
const T& Stack<T>::topElement() {
	cout << "Check Top Stack\n";
	if (!isEmpty()) {
		return top->data;
	}
}

template <class T>
bool Stack<T>::isEmpty() {
	if (top == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
class Queue {

public:
	Queue() :first(NULL), last(NULL) {
		cout << " Queue constructor\n";
	}
	~Queue() {
		cout << " Queue destructor\n";
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
		T info;
		QueueNode *next;

		QueueNode(const T& newData, QueueNode *nextNode)
			: info(newData), next(nextNode) {}
	};

	Queue(const Queue& lhs) {}
	QueueNode *first;
	QueueNode *last;

};

template <class T>
void Queue<T>::push(const T& obj) {
	cout << " PUSH Queue Operation\n";
	QueueNode *temp = new QueueNode(obj, NULL);
	if (first != NULL) {
		last->next = temp;
		last = temp;
	}
	else first = last = temp;
}

template <class T>
T Queue<T>::pop() {
	cout << " POP \n";
	cout << first->info << "\n";
	if (!isEmpty()) {
		T data = first->info;
		first = first->next;
		return data;
	}
}

template <class T>
const T& Queue<T>::topElement() {
	cout << "Check Top Queue\n";
	if (!isEmpty()) {
		return first->info;
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

	Complex z1(2,3), z2(3,5);
	

	Queue <Complex> Q;

	Q.push(z1);
	Q.push(z2);	

	cout << Q.pop() << "\n";
	
	

	




	/*z1.getNum();
	z1.show();*/

	


	/*if (z1 == z2) {
		cout << "Equal\n";
	}

	else {

		if (z1 > z2) {
			cout << "Higher\n";
		}
		else {
			cout << "Lower\n";
		}
	}*/

	

	system("pause");
	return 0;
}
