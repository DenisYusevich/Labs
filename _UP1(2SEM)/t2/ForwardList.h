#pragma once
#include<iostream>

using namespace std;

template<class T>
class Arr {


public:

	class Node {

	public:
		Node() {
		};
		~Node() {
			delete[]next;
		}

		Node*next;
		T value;
			};



	class Iterator {
	private:
		Node* ptr;
	public:
		Iterator() {};

		Iterator(Node* top) {
			ptr = top;
		}

		T getValue() {
			return ptr->value;
		}

		operator Node*() {
			return ptr;
		}

		Iterator operator ++() {
			ptr = ptr->next;
			return *this;
		}

		bool operator ==(Node* rhs) {
			return ptr == rhs;
		}

		Iterator operator =(Node* rhs) {
			ptr = rhs;
			return *this;
		}
	};
	Arr() { head = nullptr; };
	~Arr() {};
	Iterator it;

	void push_back(const T& value) {

		Node* temp = new Node;
		if (head == nullptr) {
			head = tail = temp;
			head->value = value;
			tail->value = value;
			head->next = nullptr;
			tail->next = nullptr;
			it = head;

		}
		
		else {
			tail->next = temp;
			tail = temp;
			tail->value = value;
			tail->next = nullptr;
		}
	}

	void push_front(const T& value) {
		Node* temp = new Node;
		if (head == nullptr) {
			head = tail = temp;
			head->value = value;
			tail->value = value;
			head->next = nullptr;
			tail->next = nullptr;

		}
		else {
			temp->next = head;
			head = temp;
			head->value = value;
			it = head;
			
		}
	}

	void show() {
		it = head;
		while (true) {
			cout << it.getValue() << " ";
			++it;
			if (it == nullptr)
				break;
		}
		it = head;
	}

	T operator [](int index) {
		it = head;
		int c = 0;
		while (true) {
			if (it == nullptr)
				break;
			if (c == index) {
				T temp;
				temp = it.getValue();
				return temp;
			}
			++c;
			++it;
		}
	}

	T pop_back(){
	
		it = head;
		while (true) {
			if ((*it).next == tail) {
				(*it).next = nullptr;
				break;
			}
			++it;
		}
		return (*it).value;
	
	}


private:
	Node* head;
	Node* tail;
};
