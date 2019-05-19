#include "pch.h"
#include <iostream>
using namespace std;

struct man
{
	char name[30];
	char *pSurname;

	int id;
	double size;
	double *pArray;
};

void initStruct(man *s) {
	cout << "¬ведите им€: " << endl;
	cin >> s->name;
	cout << "¬ведите фамилию: " << endl;
	s->pSurname = new char[30];
	cin >> s->pSurname;
	cout << "¬ведите id: " << endl;
	cin >> s->id;
	cout << "ƒлина массива: " << endl;
	cin >> s->size;
	s->pArray = new double[s->size];
	cout << "¬ведите значени€" << endl;
	for (int i = 0; i < s->size; i++)
	{
		cin >> s->pArray[i];
	}
}

void outputInfo(man &s) {
	cout << s.name << ' ' << s.pSurname << ' ' << ", ID: " << s.id << endl;
	cout << "—одержимое массива" << endl;
	for (int i = 0; i < s.size; i++)
	{
		cout << s.pArray[i] << ' ';
	}
	cout << endl;
}

class linkedlist {
private:
	struct node {
		man *value;
		int index;
		node *next;
	};
	
	node *head;
	int size = 0;
	
public:
	void add(man s) {
		node *pnode = new node();
		pnode->value = &s;
		pnode->index = size;
		pnode->next = nullptr;
		//node node1 = { &s, size, nullptr };
		if (size == 0) {
			head = pnode;
			size++;
			return;
		}

		node *temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = pnode;
		size++;
	}

	void deleteNode(int index) {
		node *node = head, *buf = nullptr;
		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}
		buf = node->next;
		node->next = node->next->next;
		freeMemory(buf);
		size--;
	}

	man* getAll() {
		man *arr = new man[size];
		node *node = head;
		for (int i = 0; i < size; i++)
		{
			arr[i] = *node->value;
			node = node->next;
		}
		return arr;
	}

	int getSize() {
		return size;
	}

private:
	void freeMemory(node *node) {		
		delete[] node->value->pSurname;
		delete[] node->value->pArray;
		delete node->value;
		delete node;
	}
};

class twoLinkedList {
private:
	struct node {
		man *value;
		int index;
		node *next, *prev;
	};

	node *head;
	int size = 0;

public:
	void add(man s) {
		node *pnode = new node();
		pnode->value = &s;
		pnode->index = size;
		pnode->next = nullptr;
		pnode->prev = nullptr;
		if (size == 0) {
			head = pnode;
			size++;
			return;
		}

		node *temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = pnode;
		temp->next->prev = temp;
		size++;
	}

	void deleteNode(int index) {
		node *node = head, *buf = nullptr;
		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}
		buf = node->next;
		node->next = node->next->next;
		node = node->next;
		node->prev = buf->prev;
		freeMemory(buf);
		size--;
	}

	man* getAll() {
		man *arr = new man[size];
		node *node = head;
		for (int i = 0; i < size; i++)
		{
			arr[i] = *node->value;
			node = node->next;
		}
		return arr;
	}

	int getSize() {
		return size;
	}

private:
	void freeMemory(node *node) {
		delete[] node->value->pSurname;
		delete[] node->value->pArray;
		delete node->value;
		delete node;
	}
};

class circledList {
private:
	struct node {
		man *value;
		int index;
		node *next, *prev;
	};

	node *head, *tail;
	int size = 0;

public:
	void add(man s) {
		node *pnode = new node();
		pnode->value = &s;
		pnode->index = size;
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

	void deleteNode(int index) {//todo
		node *node = head, *buf = nullptr;
		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}
		buf = node->next;
		node->next = node->next->next;
		freeMemory(buf);
		size--;
	}

	man* getAll() {
		man *arr = new man[size];
		node *node = head;
		for (int i = 0; i < size; i++)
		{
			arr[i] = *node->value;
			node = node->next;
		}
		return arr;
	}

	int getSize() {
		return size;
	}

private:
	void freeMemory(node *node) {
		delete[] node->value->pSurname;
		delete[] node->value->pArray;
		delete node->value;
		delete node;
	}
};

int main() 
{
	setlocale(LC_ALL, "");

	linkedlist llist;
	for (int i = 0; i < 5; i++)
	{
		man *s = new man();
		initStruct(s);
		llist.add(*s);
		cout << endl;
		delete s;
	}
	man *ar = llist.getAll();
	for (int i = 0; i < 5; i++)
	{
		outputInfo(ar[i]);
	}

	return 0;
}