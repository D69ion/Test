#include "pch.h"
#include <iostream>
using namespace std;

class stack {
private:
	int array[5];
	int size = -1;

public:
	void push(int value) {
		size++;
		array[size] = value;
	}

	int pop() {
		if (size == -1) {
			return NULL;
		}
		else {
			int buf = array[size];
			size--;
			return buf;
		}
	}

	int getSize() {
		return size + 1;
	}
};

class queue {
private:
	int array[5];
	int size = -1;

public:
	void push(int value) {
		size++;
		array[size] = value;
	}

	int pop() {
		if (size == -1) {
			return NAN;
		}
		else {
			int buf = array[size];
			size--;
			return buf;
		}
	}

	int getSize() {
		return size + 1;
	}
};

class linkedStack {
private:
	struct node {
		int value, index;
		node *next, *prev;
	};

	node *head;
	int size = -1;

public:
	void push(int value) {
		size++;
		node buf = { value,  size, nullptr, nullptr };
		if (size == 0) {
			head = &buf;
			return;
		}
		node *temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = &buf;
		temp->next->prev = temp;
	}

	int pop() {
		if (size == -1) {
			return NAN;
		}
		size--;
		node *node = head, *last = nullptr;
		while (node->next != nullptr) {
			node = node->next;
		}
		int buf = node->value;
		last = node;
		node = node->prev;
		node->next = nullptr;
		last->prev = nullptr;
		return buf;
	}

	int getSize() {
		return size + 1;
	}
};

class circledQueue {
private:
	struct node {
		int value, index;
		node *next;
	};

	node *head, *tail;
	int size = -1;

public:
	void push(int value) {
		size++;
		if (size == 0) {
			node hBuf = { value, size, tail };
			node tBuf = { value, size, head };
			head = &hBuf;
			tail = &tBuf;
			return;
		}
		node buf = { value, size, head };
		tail->next = &buf;
		tail = tail->next;
	}

	int pop() {
		if (size == -1) {
			return NAN;
		}
		size--;
		int buf = head->value;
		head = head->next;
		tail->next = head;
		return buf;
	}

	int getSize() {
		return size + 1;
	}
};

class priorityQueue {

};

int main()
{
	//stack stack;
	int a;
	//for (int i = 0; i < 5; i++)
	//{
	//	cin >> a;
	//	stack.push(a);
	//}
	//cout << endl;

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << stack.pop() << endl;
	//}
	//cout << endl;

	//queue q;
	//for (int i = 0; i < 5; i++)
	//{
	//	cin >> a;
	//	q.push(a);
	//}
	//cout << endl;

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << q.pop() << endl;
	//}
	//cout << endl;

	linkedStack lstack;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		lstack.push(a);
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << lstack.pop() << endl;
	}
	cout << endl;

	return 0;
}