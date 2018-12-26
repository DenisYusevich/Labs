#include<iostream>
#include<string>

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


int main() {

	string s;
	cin >> s;
	myStack<char> st;
	bool isCorrect = true;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
			continue;
		}
		if (s[i] == ')' || s[i] == '}' || s[i] == ']' && !st.isEmpty()) {
			char cur = st.pop();
			if (!((cur == '(' && s[i] == ')') || (cur == '{' && s[i] == '}') || (cur == '[' && s[i] == ']'))) {
				isCorrect = false;
				break;
			}
		}
	}
	if (isCorrect && st.isEmpty()) {
		cout << "Ok." << "\n";
	}
	else {
		cout << "UnCorrect." << "\n";
	}

	
    system("pause");
    return 0;
}


	
