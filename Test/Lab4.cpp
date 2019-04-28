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
			size--;
			return array[size];
		}
	}

	int size() {
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
			int result = array[1];
			array[1] = NAN;
			int buffer[5];
			for (int i = 0; i < size; i++)
			{
				if (this->array[i] == NAN) {
					for (int j = i + 1; j < size; j++)
					{
						this->array[j - 1] = this->array[j];
					}
					this->array[4] = NAN;
					break;
				}
			}
			size--;
			return result;
		}
	}

	int size() {
		return size + 1;
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
	void push(int value){
		size++;
		node buf = { value,  size, nullptr , nullptr };
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

	int size() {
		return size + 1;
	}
};

class circledQueue {
private:
	struct node {
		int value, index;
		node * next;
	};

	node head, tail;
	int size = -1;

public:
	void push(int value) {

	}

	int pop() {

	}

	int size() {
		return size + 1;
	}
};

class priorityQueue {

};

int main() 
{

	return 0;
}