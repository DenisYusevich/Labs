#pragma once

#include<iostream>
using namespace std;

template<class T>
class Arr {


public:

	class Node {

	public:
		Node() {
			counter++;
			currCounter = counter;
			//cout << counter;
		};
		~Node() {
			delete[]next;
		}

		Node*next;
		T value;
		static int counter;
		int currCounter;
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

		int getCounter() {
			return ptr->currCounter;
		}

		operator T*() {
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
		else if (head == tail) {
			head->next = temp;
			tail = temp;
			tail->value = value;
			tail->next = nullptr;
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
			it = head;

		}
		else {
			temp->next = head;
			head = temp;
			head->value = value;

		}
	}

	void show() {
		it = head;
		while (true) {
			cout << it.getValue();
			++it;
			if (it == nullptr)
				break;
		}
		it = head;
	}

	T operator [](int index) {
		it = head;
		while (true) {
			if (it == nullptr)
				break;
			if (it.getCounter() == index) {
				int temp;
				temp = it.getValue();
				return temp;
			}
			++it;
		}
	}


private:
	Node* head;
	Node* tail;
};

template<class T>
int Arr<T>::Node::counter = -1;
