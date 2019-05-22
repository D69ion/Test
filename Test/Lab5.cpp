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
	cout << "Введите имя: " << endl;
	cin >> s->name;
	cout << "Введите фамилию: " << endl;
	s->pSurname = new char[30];
	cin >> s->pSurname;
	cout << "Введите id: " << endl;
	cin >> s->id;
	cout << "Длина массива: " << endl;
	cin >> s->size;
	s->pArray = new double[s->size];
	cout << "Введите значения" << endl;
	for (int i = 0; i < s->size; i++)
	{
		cin >> s->pArray[i];
	}
}

void outputInfo(man &s) {
	cout << s.name << ' ' << s.pSurname << ", ID: " << s.id << endl;
	cout << "Содержимое массива" << endl;
	for (int i = 0; i < s.size; i++)
	{
		cout << s.pArray[i] << ' ';
	}
	cout << endl << endl;
}

class linkedlist {
private:
	struct node {
		man *value;
		node *next;
	};
	
	node *head;
	int size = 0;
	
public:
	void add(man *s) {
		node *pnode = new node();
		pnode->value = s;
		pnode->next = nullptr;
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
		if (index == 0) {
			head = head->next;
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
		//delete node->value;
		delete node;
	}
};

class twoLinkedList {
private:
	struct node {
		man *value;
		node *next, *prev;
	};

	node *head;
	int size = 0;

public:
	void add(man *s) {
		node *pnode = new node();
		pnode->value = s;
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
		if (index == 0) {
			head = head->next;
			head->prev = nullptr;
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
		//delete node->value;
		delete node;
	}
};

class circledList {
private:
	struct node {
		man *value;
		node *next, *prev;
	};

	node *head, *tail;
	int size = 0;

public:
	void add(man *s) {
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
		//delete node->value;
		delete node;
	}
};

void testLinkedList() {
	int a = 0;
	linkedlist llist;
	man *s = new man[5];
	for (int i = 0; i < 5; i++)
	{
		initStruct(&s[i]);
		llist.add(&s[i]);
		cout << endl;
	}
	man *ar = llist.getAll();
	for (int i = 0; i < 5; i++)
	{
		outputInfo(ar[i]);
	}
	cout << "Индекс удаляемого элемента" << endl;
	cin >> a; cout << endl;
	llist.deleteNode(a);
	man *ar1 = llist.getAll();
	for (int i = 0; i < 4; i++)
	{
		outputInfo(ar1[i]);
	}
}

void testTwoLinkedList() {
	int a = 0;
	twoLinkedList tllist;
	man *s = new man[5];
	for (int i = 0; i < 5; i++)
	{
		initStruct(&s[i]);
		tllist.add(&s[i]);
		cout << endl;
	}
	man *ar = tllist.getAll();
	for (int i = 0; i < 5; i++)
	{
		outputInfo(ar[i]);
	}
	cout << "Индекс удаляемого элемента" << endl;
	cin >> a; cout << endl;
	tllist.deleteNode(a);
	man *ar1 = tllist.getAll();
	for (int i = 0; i < 4; i++)
	{
		outputInfo(ar1[i]);
	}
}

void testCircledList() {
	int a = 0;
	circledList clist;
	man *s = new man[5];
	for (int i = 0; i < 5; i++)
	{
		initStruct(&s[i]);
		clist.add(&s[i]);
		cout << endl;
	}
	man *ar = clist.getAll();
	for (int i = 0; i < 5; i++)
	{
		outputInfo(ar[i]);
	}
	cout << "Индекс удаляемого элемента" << endl;
	cin >> a; cout << endl;
	clist.deleteNode(a);
	man *ar1 = clist.getAll();
	for (int i = 0; i < 4; i++)
	{
		outputInfo(ar1[i]);
	}

}

int main() 
{
	setlocale(LC_ALL, "");

	testLinkedList();
	testTwoLinkedList();
	testCircledList();

	return 0;
}