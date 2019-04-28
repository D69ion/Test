#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

#pragma warning(disable:4996)

struct people
{
	char name[30];
	char *pSurname;

	int id;
	double size;
	double *pArray;
};

void fillArray(people *s) {
	cout << "Длина массива: " << endl;
	cin >> s->size;
	s->pArray = new double[s->size];
	cout << "Введите значения" << endl;
	for (int i = 0; i < s->size; i++)
	{
		cin >> s->pArray[i];
	}
}

void printArray(people &s) {
	cout << "Содержимое массива" << endl;
	for (int i = 0; i < s.size; i++)
	{
		cout << s.pArray[i] << ' ';
	}
	cout << endl;
}

void fillInfo(people *s) {
	cout << "Введите имя: " << endl;
	cin >> s->name;
	cout << "Введите фамилию: " << endl;
	s->pSurname = new char[30];
	cin >> s->pSurname;
	cout << "Введите id: " << endl;
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
		for (int j = 0; j < p[i].size; j++)
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
		p[i].pSurname = new char[30];
		in >> p[i].pSurname;
		in >> p[i].id;
		in >> p[i].size;
		p[i].pArray = new double[p[i].size];
		for (int j = 0; j < p[i].size; j++)
		{
			in >> p[i].pArray[j];
		}
	}
	in.close();
}

void writeBinFile(people *&p, FILE *file) {
	file = fopen("file.bin", "wb");
	for (int i = 0; i < 3; i++)
	{
		//fwrite(&p[i], sizeof(people), 1, file);
		fwrite(&p[i].name, 30, 1, file);
		fwrite(&p[i].pSurname, 30, 1, file);
		fwrite(&p[i].id, sizeof(int), 1, file);
		fwrite(&p[i].size, sizeof(double), 1, file);
		for (int j = 0; j < p[i].size; j++)
		{
			fwrite(&p[i].pArray[j], sizeof(double), 1, file);
		}
	}
	fclose(file);
}

void readBinFile(people *&p, FILE *file) {
	file = fopen("file.bin", "rb");
	for (int i = 0; i < 3; i++)
	{
		fread(&p[i].name, 30, 1, file);
		p[i].pSurname = new char[30];
		fread(&p[i].pSurname, 30, 1, file);
		fread(&p[i].id, sizeof(int), 1, file);
		fread(&p[i].size, sizeof(double), 1, file);
		for (int j = 0; j < p[i].size; j++)
		{
			fread(&p[i].pArray[j], sizeof(double), 1, file);
		}
	}
	fclose(file);
}

int maine()
{
	setlocale(LC_ALL, "");

	people *pSrc = new people[3];
	people *pTxtAr = new people[3];
	people *pBinAr = new people[3];
	FILE *binWr = nullptr, *binR = nullptr;

	for (int i = 0; i < 3; i++)
	{
		initStruct(&pSrc[i]);
		cout << endl;
	}
	writeTextFile(pSrc);
	writeBinFile(pSrc, binWr);

	cout << "Содержимое исходного массива" << endl;
	for (int i = 0; i < 3; i++)
	{
		outputInfo(pSrc[i]);
		printArray(pSrc[i]);
	}

	cout << endl;
	cout << "Содержимое массива после считывания текстового файла" << endl;
	readTextFile(pTxtAr);
	for (int i = 0; i < 3; i++)
	{
		outputInfo(pTxtAr[i]);
		printArray(pTxtAr[i]);
	}

	cout << endl;
	cout << "Содержимое массива после считывания бинарного файла" << endl;
	readBinFile(pBinAr, binR);
	for (int i = 0; i < 3; i++) 
	{
		outputInfo(pBinAr[i]);
		printArray(pBinAr[i]);
	}
	return 0;
}