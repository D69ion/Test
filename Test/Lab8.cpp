#include "pch.h"
#include <iostream>
using namespace std;


class circledList {
private:
	struct node {
		int value;
		node *next, *prev;
	};

	node *head, *tail;
	int size = 0;

public:
	void add(int s) {
		node *pnode = new node();
		pnode->value = s;
		pnode->next = nullptr;
		pnode->prev = nullptr;
		if (size == 0) {
			head = pnode;
			head->next = tail;
			tail = pnode;
			tail->next = head;
			tail->prev = head;
			size++;
			return;
		}

		tail->next = pnode;
		pnode->next = head;
		pnode->prev = tail;
		tail = pnode;
		size++;
	}

	void deleteNode(int index) {
		node *node = head, *buf = nullptr;
		if (index == 0) {
			head = head->next;
			head->prev = nullptr;
			freeMemory(node);
			size--;
			return;
		}
		if (index == size - 1) {
			node = tail;
			tail = tail->prev;
			tail->next = head;
			freeMemory(node);
			size--;
			return;
		}
		for (int i = 0; i < index - 1; i++)
		{
			node = node->next;
		}
		buf = node->next;
		node->next = buf->next;
		node->prev = buf->prev;
		freeMemory(buf);
		size--;
	}

	int* getAll() {
		int *arr = new int[size];
		node *node = head;
		for (int i = 0; i < size; i++)
		{
			arr[i] = node->value;
			node = node->next;
		}
		return arr;
	}

	int getSize() {
		return size;
	}

private:
	void freeMemory(node *node) {
		delete node;
	}
};

void testArray() {

}

void testList() {

}

int main()
{
	setlocale(LC_ALL, "");

	testList();
	testArray();
	
	return 0;
}