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

	int getIndex(int key) {
		node *buf = head;
		for (int i = 0; i < size; i++)
		{
			if (buf->value == key) {
				return i;
			}
			buf = buf->next;
		}
		return -1;
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

void selectionSort(int *array, int size) {
	int min, temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

int get(int key, int *array, int size) {
	for (int i = 0; i < size; i++)
	{
		if (array[i] == key) {
			return i;
		}
	}
	return NULL;
}

int binarySearch(int key, int *array, int size) {
	int left = 0, right = size - 1, middle;
	while (true) {
		middle = (left + right) / 2;
		if (key == array[middle]) {
			return middle;
		}
		if (key > array[middle]) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}

		if (left > right) {
			return-1;
		}
	}
	return 0;
}

void testArray() {
	cout << "Test array" << endl;
	int const size = 5;
	int array[size];
	int key;
	cout << "Enter array values" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
	cout << "Value to find: ";
	cin >> key;
	cout << "Value index: " << get(key, array, size) << endl;
	selectionSort(array, size);
	cout << "Array after selection sort: ";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
	cout << "Value index after selection sort: " << binarySearch(key, array, size) << endl << endl;
}

void testList() {
	cout << "Test list" << endl;
	int size, buf, key;
	circledList clist;
	cout << "Enter the number of input elements: ";
	cin >> size;
	cout << "Enter list values" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> buf;
		clist.add(buf);
	}
	cout << "Value to find: ";
	cin >> key;
	cout << "Value index: " << clist.getIndex(key) << endl;
}

int mainu()
{
	setlocale(LC_ALL, "");

	testArray();
	testList();

	return 0;
}