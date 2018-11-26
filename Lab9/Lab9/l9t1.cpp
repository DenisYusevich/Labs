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


	//char c[] = "(арварв}(dsdk)[)[]";

	//stack<char> st;

	////st.pushChar(c);

	//bool flag = true;
	//for (int i = 0; i < 22; ++i) {
	//	if (c[i] == '(' || c[i] == '[' || c[i] == '{') {
	//		st.push(c[i]);
	//		cout << c[i] << " ";
	//	}


	//	if (c[i] == ')' || c[i] == ']' || c[i] == '}') {


	//		if (st.empty()) {
	//			flag = false;
	//			break;
	//		}

	//		else {
	//			st.pop();
	//		}
	//		

	//		
	//	}

	//}

	//	if (flag == true) {
	//		cout << "Alright";
	//	}
	//	else {
	//		cout << "Smth is wrong\n";
	//	}









		myStack<const char*>st;

		
		cout << st.isEmpty();
		st.pop();







		system("pause");
		return 0;



	
}