#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

struct people
{
	char name[30];
	char *pSurname;

	int id;
	double size;
	double *pArray;
};

void fillArray(people *s) {
	cout << "ƒлина массива: " << endl;
	cin >> s->size;
	s->pArray = new double[s->size];
	cout << "¬ведите значени€" << endl;
	for (int i = 0; i < s->size; i++)
	{
		cin >> s->pArray[i];
	}
}

void printArray(people &s) {
	cout << "—одержимое массива" << endl;
	for (int i = 0; i < s.size; i++)
	{
		cout << s.pArray[i] << ' ';
	}
	cout << endl;
}

void fillInfo(people *s) {
	cout << "¬ведите им€: " << endl;
	cin >> s->name;
	cout << "¬ведите фамилию: " << endl;
	s->pSurname = new char[30];
	cin >> s->pSurname;
	cout << "¬ведите id: " << endl;
	cin >> s->id;
}

void outputInfo(people &s) {
	cout << s.name << ' ' << s.pSurname << ' ' << ", ID: " << s.id << endl;
}

void freeMemory(people *s) {
	delete[] s->pSurname;
	delete[] s->pArray;
}

void initStruct(people *s) {
	fillInfo(s);
	fillArray(s);
}

void writeTextFile(people *&p) {
	ofstream out;
	out.open("file.txt", ios::trunc);
	for (int i = 0; i < 3; i++)
	{
		out << p[i].name << ' ' << p[i].pSurname << endl << p[i].id << endl << p[i].size << endl;
		for (int j = 0; j < p[i].size; i++)
		{
			out << p[i].pArray[j] << ' ';
		}
		out << endl;
	}
	out.close();
}

void readTextFile(people *&p) {
	ifstream in;
	in.open("file.txt", ios::in);
	for (int i = 0; i < 3; i++)
	{
		in >> p[i].name;
		in >> p[i].pSurname;
		in >> p[i].id;
		in >> p[i].size;
		p[i].pArray = new double[p[i].size];
		for (int j = 0; j < p[i].size; i++)
		{
			in >> p[i].pArray[j];
		}
	}
	in.close();
}

void writeBinFile(people *&p) {

}

void readBinFile(people *&p) {

}

int main()
{
	setlocale(LC_ALL, "");

	people *pPw = new people[3];
	people *pPr = new people[3];
	people *pPb = new people[3];

	for (int i = 0; i < 3; i++)
	{
		initStruct(&pPw[i]);
		cout << endl;
	}
	writeTextFile(pPw);

	for (int i = 0; i < 3; i++)
	{
		outputInfo(pPw[i]);
		printArray(pPw[i]);
	}

	readTextFile(pPr);
	for (int i = 0; i < 3; i++)
	{
		outputInfo(pPr[i]);
		printArray(pPr[i]);
	}
	return 0;
}