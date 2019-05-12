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
			array[size] = NAN;
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
	int index = -1;

public:
	void push(int value) {
		index++;
		array[index] = value;
	}

	int pop() {
		if (index == -1) {
			return NAN;
		}
		else {
			int buf = array[0];
			for (int i = 1; i < index + 1; i++)
			{
				array[i - 1] = array[i];
			}
			array[index] = NAN;
			index--;
			return buf;
		}
	}

	int getSize() {
		return index + 1;
	}
};

class linkedStack {
private:
	struct node {
		int value, index;
		node *next, *prev;
	};

	node head;
	int size = -1;

public:
	void push(int value) {
		size++;
		node buf = { value,  size, nullptr, nullptr };
		if (size == 0) {
			head = buf;
			return;
		}
		node *temp = &head;
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
		node *node = &head, *last = nullptr;
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
	int array[5];
	int size = 0, push_index = 0, pop_index = 0;

public:
	void push(int value) {
		if (push_index == 5) {
			push_index = 0;
		}
		if (array[push_index] == 0 || array[push_index] == -858993460) {
			array[push_index] = value;
			size++;
			push_index++;
		}
	}

	int pop() {
		if (size == 0) {
			return NAN;
		}

		if (pop_index == 5) {
			pop_index = 0;
		}
		int buf = array[pop_index];
		array[pop_index] = NAN;
		pop_index++;
		size--;
		return buf;
	}

	int getSize() {
		return size;
	}
};

int main()
{
	stack stack;
	int a;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		stack.push(a);
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << stack.pop() << endl;
	}
	cout << endl;

	queue q;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		q.push(a);
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << q.pop() << endl;
	}
	cout << endl;

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

	circledQueue cqueue;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		cqueue.push(a);
	}
	cout << endl;

	for (int i = 0; i < 1; i++)
	{
		cout << cqueue.pop() << endl;
	}
	cin >> a;
	cqueue.push(a);
	for (int i = 0; i < 5; i++)
	{
		cout << cqueue.pop() << endl;
	}

	cout << endl;

	return 0;
}