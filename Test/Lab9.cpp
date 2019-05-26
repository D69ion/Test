#include "pch.h"
#include <iostream>
using namespace std;

class tree {
private:
	struct node {
		int value;
		node *left, *right;
	};

	node *root = nullptr;
	int size = 0;
	
public:
	void add(int value) {
		if (root == nullptr) {
			root = new node();
			root->value = value;
			root->left = root->right = nullptr;
		}
		else {
			add(value, root);
		}
	}

	void deleteNode(int value) {

	}

	node* get(int key) {
		if (root = nullptr) {
			return nullptr;
		}
		
		return get(key, root);
	}

	void preorder() {
		//работать с массивами в рекурсии и вывод в конце основного метода
	}

	void inorder() {

	}

	void postorder() {

	}
	
private:
	void add(int value, node *node) {

	}

	void deleteNode(int value, node *node) {

	}

	node* get(int key, node *node) {

	}

	void preorder(node *node) {

	}

	void inorder(node *node) {

	}

	void postorder(node *node) {

	}
};

int main() {

	return 0;
}