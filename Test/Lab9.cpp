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
			size++;
		}
		else {
			add(value, root);
		}
	}

	void deleteNode(int value) {
		if (root == nullptr) {
			return;
		}

		delete(value, root);
	}

	node* get(int key) {
		if (root == nullptr) {
			return nullptr;
		}
		
		return get(key, root);
	}

	int* preorder() {
		//работать с массивами в рекурсии и вывод в конце основного метода

	}

	int* inorder() {

	}

	int* postorder() {

	}
	
private:
	void add(int value, node *current) {
		if (current == nullptr || value == current->value) {
			return;
		}
		if (value < current->value) {
			if (current->left == nullptr) {
				current->left = new node();
				current->left->value = value;
				size++;
			}
			else {
				add(value, current->left);
			}
		}
		else if (value > current->value) {
			if (current->right == nullptr) {
				current->right = new node();
				current->right->value = value;
				size++;
			}
			else {
				add(value, current->right);
			}
		}
	}

	void deleteNode(int value, node *current) {

	}

	node* get(int key, node *current) {
		if (current == nullptr) {
			return nullptr;
		}
		if (key == current->value) {
			return current;
		}
		if (key < current->value) {
			get(key, current->left);
		}
		else {
			get(key, current->right);
		}
	}

	void preorder(node *current) {

	}

	void inorder(node *current) {

	}

	void postorder(node *current) {

	}
};

int main() {

	return 0;
}