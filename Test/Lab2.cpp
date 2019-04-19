#include "pch.h"
#include <iostream>
using namespace std;

struct something 
{
	char name[30];
	char *pSurname;

	int id;
	double size;
	double *pArray;
};

void fillArray(something *s) {
	cout << "ƒлина массива: " << endl;
	cin >> s->size;
	s->pArray = new double[s->size];
	cout << "¬ведите значени€" << endl;
	for (int i = 0; i < s->size; i++)
	{
		cin >> s->pArray[i];
	}
}

void printArray(something &s) {
	cout << "—одержимое массива" << endl;
	for (int i = 0; i < s.size; i++)
	{
		cout << s.pArray[i] + ' ';
	}
	cout << endl;
}

void fillInfo(something *s) {
	cout << "¬ведите им€: " << endl;
	cin >> s->name;
	cout << "¬ведите фамилию: " << endl;
	s->pSurname = new char[30];
	cin >> s->pSurname;
	cout << "¬ведите id: " << endl;
	cin >> s->id;
}

void outputInfo(something &s) {
	cout << s.name + ' ' << s.pSurname + ' ' << ", ID: " + s.id << endl;
}

void freeMemory(something *s) {
	delete[] s->pSurname;
	delete[] s->pArray;
}

void initStruct(something *s) {
	fillInfo(s);
	fillArray(s);
}

void incr(int *x) {
	(*x)++;
	cout << *x << endl;
}

int main()
{
	setlocale(LC_ALL, "");

	int a = 4;
	incr(&a);

	something s;
	something *ps;
	ps = new something[3];

	initStruct(&s);
	cout << endl;
	outputInfo(s);
	printArray(s);
	cout << endl;

	/*for (int i = 0; i < 3; i++)
	{
		initStruct(&ps[i]);
		cout << endl;
		outputInfo(ps[i]);
		printArray(ps[i]);
		cout << endl;
	}*/

	freeMemory(&s);
	//for (int i = 0; i < 3; i++)
	//{
	//	freeMemory(&ps[i]);
	//}
	//delete[] ps;
	return 0;
}