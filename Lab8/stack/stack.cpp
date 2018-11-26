#include<iostream>


using namespace std;



class Node {


public:
	int value;
	Node* prev;

};


class myStack {

private:
	Node* top;

public:

	void push(int c) {
	
		Node* temp;
		temp = new Node;
		top = temp;
	
	}
	int  pop() {
	
		int value = top->value;
		Node*temp = top;
		top = top->prev;
		delete temp;
		return value;
	}


};



int main() {


	myStack SS;

	SS.push(5);
	SS.push(3);

	cout << SS.pop();

	system("pause");
	return 0;


}






