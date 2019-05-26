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

	void deletenode(int value) {
		if (root == nullptr) {
			return;
		}

		deleteNode(root, value);
		//deletenode(get(value));
	}

	node* get(int key) {
		if (root == nullptr) {
			return nullptr;
		}

		return get(key, root);
	}

	void preorder(node* current) {
		if (current == nullptr) {
			return;
		}

		cout << current->value << ' ';
		preorder(current->left);
		preorder(current->right);
	}

	void inorder(node* current) {
		if (current == nullptr) {
			return;
		}

		inorder(current->left);
		cout << current->value << ' ';
		inorder(current->right);
	}

	void postorder(node* current) {
		if (current == nullptr) {
			return;
		}

		postorder(current->left);
		postorder(current->right);
		cout << current->value << ' ';
	}

	node* getRoot() {
		return root;
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

	node* deleteNode(node* current, double key) {
		if (current == nullptr) {
			return current;
		}

		if (current->value == key) {
			node *temp;

			if (current->right == nullptr) {
				temp = current->left;
			}
			else {
				temp = current->right;

				if (temp->left == nullptr) {
					temp->left = current->left;
				}
				else {
					node *min = temp->left;

					while (min->left != nullptr) {
						temp = min;
						min = temp->left;
					}

					temp->left = min->right;
					min->left = current->left;
					min->right = current->right;
					temp = min;
				}
			}

			if (current == root) {
				root = temp;
			}

			delete current;
			return temp;
		}
		else if (key < current->value) {
			current->left = deleteNode(current->left, key);
		}
		else {
			current->right = deleteNode(current->right, key);
		}

		return current;
	}

	//void deletenode(node* current) {
	//	node *temp = nullptr;

	//	if (current->right == nullptr) {
	//		temp = current->left;
	//	}
	//	else {
	//		temp = current->right;

	//		if (temp->left == nullptr) {
	//			temp->left = current->left;
	//		}
	//		else {
	//			node* min = temp->left;

	//			while (min->left != nullptr) {
	//				temp = min;
	//				min = temp->left;
	//			}

	//			temp->left = min->right;
	//			min->left = current->left;
	//			min->right = current->right;
	//			temp = min;
	//		}
	//	}

	//	delete current;
	//}

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

	//void preorder(node *current) {

	//}

	//void inorder(node *current) {

	//}

	//void postorder(node *current) {

	//}
};

int main() {
	tree btree;
	int a;
	for (int i = 0; i < 6; i++)
	{
		cin >> a;
		btree.add(a);
	}
	btree.preorder(btree.getRoot());
	cout << endl;

	cout << "deleted node" << endl;
	cin >> a;
	btree.deletenode(a);
	cout << endl;
	btree.preorder(btree.getRoot());

	return 0;
}