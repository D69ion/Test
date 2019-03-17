// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	//1-3(пофиксить создание массива с клавиатуры)
	cout << "Задания №1-3" << "\r\n";
	//cout << "введите размерность массива: "; 
	//int n = 0;
	//cin >> n;
	int arr[4];
	int size = sizeof(arr) / 4;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\r\n";
	}
	cout << "введите значения массива" << "\r\n";
	for (int i = 0; i < size; i++) 
	{
		cin >> arr[i];
	}
	cout << "повторная проверка" << "\r\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << "\r\n";

	//4-5
	cout << "Задания №4-5" << "\r\n";
	int *p = arr;
	cout << "адрес массива: " << &arr << "\r\n";
	cout << "адрес указателя: " << &p << "\r\n";
	cout << "содержимое указателя: " << *p << "\r\n";
	cout << "содержимое массива" << "\r\n";
	for (int i = 0; i < size; i++) 
	{
		cout << p[i] << "  ";
	}
	cout << "\r\n";

	//6
	cout << "Задание №6" << "\r\n";
	static double dArr[5];
	int size = sizeof(dArr) / 4;
	for (int i = 0; i < 5; i++)
	{
		cout << dArr[i] << "\r\n";
	}
	cout << "введите значения массива" << "\r\n";
	for (int i = 0; i < 5; i++)
	{
		cin >> dArr[i];
	}
	cout << "повторная проверка" << "\r\n";
	for (int i = 0; i < 5; i++)
	{
		cout << dArr[i] << "  ";
	}
	cout << "\r\n";

	//7
	cout << "Задание №7" << "\r\n";
	p = new int[6];
	for (int *i = p; i != p + 5; i++)
	{
		cout << *i << "\r\n";
	}
	cout << "введите значения массива" << "\r\n";
	for (int *i = p; i != p + 5; i++)
	{
		cin >> *i;
	}
	cout << "повторная проверка" << "\r\n";
	for (int *i = p; i != p + 5; i++)
	{
		cout << *i << "  ";
	}
	cout << "\r\n";

	//8
	cout << "Задание №8" << "\r\n";
	delete[] p;
	double **d = new double*[5];
	for (int i = 0; i < 5; i++)
	{
		d[i] = new double[5];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			d[i][j] = 1;
			cout << d[i][j] << " ";
		}
		cout << "\r\n";
	}
	
	for (int i = 0; i < 5; i++) 
	{
		delete[] d[i];
	}
	delete[] d;

	//9
	cout << "Задание №9" << "\r\n";
	char cArr[5][5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				cArr[i][j][k] = 'q';
			}
		}
	}

	cout << cArr[1][2][3] << "\r\n";

	//10
	cout << "Задание №10" << "\r\n";
	char ***c = new char**[5];
	for (int i = 0; i < 5; i++)
	{
		c[i] = new char*[5];
		for (int j = 0; j < 5; j++)
		{
			c[i][j] = new char[5];
			for (int k = 0; k < 5; k++)
			{
				c[i][j][k] = 'q';
			}
		}
	}
	cout << c[1][1][1] << "\r\n";

	//11
	cout << "Задание №11" << "\r\n";
}



/*#include "pch.h" 
#include <iostream> 
using namespace std;

int integers[10];
int *pInt;
static double doubles[10];
double **array;

double getRandomDouble(double, double); // А КАКОГО ХРЕНА??? ЗАЧЕМ ОБЪЯВЛЯТЬ ФУНКЦИЮ????????? И ПОЧЕМУ ИМЕННО ЗДЕСЬ??? 

void task1() {
	cout « "output init int array" « endl;
	int size = sizeof(integers) / sizeof(integers[0]); //sizeof() get length of value in bytes 
	for (int i = 0; i < size; i++)
	{
		cout « integers[i] « ' ';
	}
	cout « endl;
}

void task2() {
	cout « "input int array" « endl;
	int size = sizeof(integers) / sizeof(integers[0]);
	for (int i = 0; i < size; i++)
	{
		cin » integers[i];
	}
}

void task3() {
	cout « "output int array" « endl;
	int size = sizeof(integers) / sizeof(integers[0]);
	for (int i = 0; i < size; i++)
	{
		cout « integers[i] « ' ';
	}
	cout « endl;
}

void task4() {
	pInt = integers;

	cout « "Address of int array = " « &integers « endl;
	cout « "Address ofint pointer = " « &pInt « endl;
	cout « "Value of int pointer = " « *pInt « endl;
}

void task5() {
	cout « "output int array using pointer" « endl;
	int size = sizeof(integers) / sizeof(integers[0]);
	for (int i = 0; i < size; i++)
	{
		cout « pInt[i] « ' ';
	}
	cout « endl;
}

void task6() {
	cout « "output init double array" « endl;
	int size = sizeof(integers) / sizeof(integers[0]);
	size = sizeof(doubles) / sizeof(doubles[0]);
	for (int i = 0; i < size; i++)
	{
		cout « doubles[i] « ' ';
	}
	cout « endl;
	cout « "input double array" « endl;
	for (int i = 0; i < size; i++)
	{
		cin » doubles[i];
	}
	cout « "output double array" « endl;
	for (int i = 0; i < size; i++)
	{
		cout « doubles[i] « ' ';
	}
	cout « endl;
}

void task7() {
	int size = 10;
	pInt = new int[size]();// each init value is 0, but pInt = new int[10]; // each init value is undefined 
	cout « "output init int pointer" « endl;
	for (int i = 0; i < size; i++)
	{
		cout « pInt[i] « ' ';
	}
	cout « endl;
	cout « "input int pointer" « endl;
	for (int i = 0; i < size; i++)
	{
		cin » pInt[i];
	}
	cout « "output int pointer" « endl;
	/*for (int i = 0; i < size; i++)
	{
	cout « pInt[i] « ' ';
	}
	for (int *q = pInt; q != pInt + size; q++) {
		cout « *q « ' ';
	}
	delete[] pInt;
	cout « endl;
}

void task8() {
	int rows = 5, columns = 5;
	double **array = new double*[rows]();
	for (int i = 0; i < rows; i++)
	{
		array[i] = new double[columns]();
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//array[i][j] = rand() % 10;// 0-10 
			//array[i][j] = 1 * (double)rand() / RAND_MAX; 
			array[i][j] = getRandomDouble(0, 1);
		}
	}

	cout « "Matrix" « endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout « array[i][j] « '\t';
		}
		cout « endl;
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}

double getRandomDouble(double begin, double end) {
	return begin + (end - begin) * (double)rand() / RAND_MAX;
}

int main()
{
	//task1(); 
	//task2(); 
	//task3(); 

	//task4(); 
	//task5(); 
	//task6(); 
	//task7(); 
	task8();

	// 2 3 4 5 1 6 7 6 8 9 
	//2.1 3.24 4.45 5.001 1.123 6.6 7.0 6.9 8.1237 9.3444 

	system("pause");
}*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
