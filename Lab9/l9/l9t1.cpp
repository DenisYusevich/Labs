#include<iostream>
#include<stack>

using namespace std;


class Node {

public:
	char valueChar;
	int value;
	Node* prev;

};


//class NodeChar {
//
//public:
//	char valueChar;
//	NodeChar* prevChar;
//
//};

class myStack {

private:
	Node* top;
	//NodeChar* topChar;

public:
	void push(int c) {
	
		Node *pv = new Node;
		pv->value = c;
		pv->prev = top;
		top = pv;
	}

	void pushChar( char c) {

		Node *pv = new Node;
		pv->valueChar = c;
		pv->prev = top;
		top = pv;
	}

	int pop() {

		if (isEmpty())
		{
			return -1;
		}
		int temp = top->value;
		Node *pv = top;
		top = top->prev;
		delete pv;
		return temp;

	}

	char popChar() {

		if (isEmpty())
		{
			return 0;
		}
		char temp = top->valueChar;
		Node *pv = top;
		top = top->prev;
		delete pv;
		return temp;

	}

	bool isEmpty()
	{
		return top ? false : true;
	}
	/*bool isEmptyChar() {
		return topChar ?  false : true;
	}*/

};


int main() {


	char c[] = "(арварв}(dsdk)[)[]";

	stack<char> st;

	//st.pushChar(c);

	bool flag = true;
	for (int i = 0; i < 22; ++i) {
		if (c[i] == '(' || c[i] == '[' || c[i] == '{') {
			st.push(c[i]);
			cout << c[i] << " ";
		}


		if (c[i] == ')' || c[i] == ']' || c[i] == '}') {


			if (st.empty()) {
				flag = false;
				break;
			}

			else {
				st.pop();
			}
			

			
		}

	}

		if (flag == true) {
			cout << "Alright";
		}
		else {
			cout << "Smth is wrong\n";
		}

		system("pause");
		return 0;



	
}