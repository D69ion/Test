#include "pch.h"
#include <iostream>
using namespace std;

void buble_sort(int *array) {
	int temp;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void selection_sort(int *array) {
	int min, temp;
	for (int i = 0; i < 9; i++)
	{
		min = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

int mainy()
{
	setlocale(LC_ALL, "");

	int arrayBS[10];
	int arraySS[10];
	cout << "Введите значения массива" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> arrayBS[i];
		arraySS[i] = arrayBS[i];
	}
	buble_sort(arrayBS);
	selection_sort(arraySS);

	cout << "Отсоритированный массив с помощью пузырьковой сортировки" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arrayBS[i] << ' ';
	}
	cout << endl;

	cout << "Отсоритированный массив с помощью сортировки отбором" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arraySS[i] << ' ';
	}
	cout << endl;

	return 0;
}