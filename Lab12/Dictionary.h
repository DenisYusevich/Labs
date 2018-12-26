#pragma once
#include<iostream>
#include<string.h>

using namespace std;



template<class keyT,class dataT>
class Dictionary {

private:


	class Node {

	public:

		Node();
		Node(keyT key, dataT data);
		keyT key;
		Node* right;
		Node* left;
		dataT data;
		void showData();
	};


	void add(Node*&node, keyT key, dataT data);
	Node* root;
	Node* search(Node*&node, keyT key) {

		//*try {
		//	if (node == NULL) { throw "element doesn't exist"; }
		//}
		//catch (string str) {
		//	cout << str;
		//}*/
		if (key == node->key) {

			return node;
		}
		else if (key > node->key) {
			search(node->right, key);
		}
		else if (key < node->key) {
			search(node->left, key);

		}
	};

	void del(Node*&node) {
		if (node != NULL) {

			del(node->right);
			del(node->left);
			delete node;
			node = NULL;	
		}
	}


public:


	Dictionary() {
		root = NULL;
	}

	void add(keyT key, dataT data) {
		add(root, key, data);
	};
	//void del();
	Node* search(keyT key) {
		return search(root, key);
	};

	void del() {
		del(root);
	}
};


template<class keyT,class dataT>
void Dictionary<keyT,dataT>:: Node::showData() {

	cout << data;

}

template<class keyT, class dataT>
Dictionary<keyT,dataT>::Node::Node() {

	left = NULL;
	right = NULL;

}

template<class keyT, class dataT>
Dictionary<keyT,dataT>::Node::Node(keyT key,dataT data) {

	this->key = key;
	this->data = data;
	left = NULL;
	right = NULL;

}


template<class keyT, class dataT>
void Dictionary<keyT, dataT>::add(Node*&node, keyT key,dataT data) {

	if (node == NULL) {

		node = new Node(key,data);

	}
	else if (key > node->key) {
		add(node->right,key,data);
	}
	else if (key < node->key) {
		add(node->left, key,data);
	}

	
}

//template<class keyT, class dataT>
//Node* Dictionary<keyT, dataT>::search(Node*&node, keyT key) {
//
//	
//	if (key == node->key) {
//		return node;
//	}
//	else if (key > node->key) {
//		search(node->right, key);
//	}
//	else if (key < node->key) {
//		search(node->left, key);
//
//	}
//
//
//}

