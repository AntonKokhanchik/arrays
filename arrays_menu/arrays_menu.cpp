// arrays_menu.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "arrays.h"
#include "conio.h"
#include "iostream"
#include "time.h"

using namespace std;

int main()
{
	char ch;
	arrays a;

	do
	{
		ch = mainMenu(ch, a);
	} while (ch != 27);

	return 0;
}

char mainMenu(char ch, arrays& a)
{
	printMainMenu();

	do {
		ch = _getch();
	} while (ch != 27 || ch < '1' || ch > '3');

	if (ch != 27)
		executeMainMenu(ch, a);

	return ch;
}

void printMainMenu()
{
	cout << "Press:\n"
		<< "1 to create array\n"
		<< "2 to sort array\n"
		<< "3 to find element\n"
		<< "esc to exit";
}

void executeMainMenu(char ch, arrays& a)
{
	switch (ch)
	{
	case '1': createArrayMenu(a); break;
	case '2': sortArrayMenu(a); break;
	case '3': searchMenu(a); break;
	}
}

void createArrayMenu(arrays& a)
{
	char ch;

	printCreateArrayMenu();

	do
	{
		ch = _getch();
	} while (ch != 27 || ch < '1' || ch > '2');

	if (ch != 27)
		executeCreateArrayMenu(ch, a);
}

void printCreateArrayMenu()
{
	cout << "Press\n"
		<< "1 to to create array manually\n"
		<< "2 to create random array"
		<< "esc to cancel";
}

void executeCreateArrayMenu(char ch, arrays& a)
{
	switch (ch)
	{
	case '1': createArrayManually(a); break;
	case '2': createRandomArray(a); break;
	}
}

void createArrayManually(arrays& a)
{
	int l;

	cout << "Enter length: ";
	cin >> l;
	a.reinit(l);

	cout << "enter elements:\n";
	for (int i = 0; i < l; i++)
		cin >> a[i];
}

void createRandomArray(arrays& a)
{
	srand(time(NULL));
	int l;

	cout << "Enter length: ";
	a.reinit(l);

	for (int i = 0; i < l; i++)
		a[i] = rand() % 100000;
}

void sortArrayMenu(arrays& a)
{
	char ch;

	printSortArrayMenu();

	do
	{
		ch = _getch();
	} while (ch != 27 || ch < '1' || ch > '8');

	if (ch != 27)
		executeSortArrayMenu(ch, a);
}

void printSortArrayMenu()
{
	cout << "press to execute:\n"
		<< "1 - selection sort\n"
		<< "2 - insertion sort\n"
		<< "3 - shaker sort\n"
		<< "4 - comb sort\n"
		<< "5 - quick sort\n"
		<< "6 - piramidal sort\n"
		<< "7 - block sort\n"
		<< "8 - bit sort\n"
		<< "esc to cancel";
}

void executeSortArrayMenu(char ch, arrays& a)
{
	switch (ch)
	{
	case '1': a.selectionSort(); break;
	case '2': a.insertionSort(); break;
	case '3': a.shakerSort(); break;
	case '4': a.combSort(); break;
	case '5': a.quickSort(); break;
	case '6': a.piramidalSort(); break;
	case '7': a.blockSort(); break;
	case '8': a.bitSort(); break;
	}
}

void searchMenu(arrays& a)
{
	char ch;

	printSearchMenu();

	do
	{
		ch = _getch();
	} while (ch != 27 || ch < '1' || ch > '2');

	if (ch != 27)
		executeSearchMenu(ch, a);
}

void printSearchMenu()
{
	cout << "press to execute:\n"
		<< "1 - interpolation search\n"
		<< "2 - binary tracking search\n"
		<< "esc to cncel";
}

void executeSearchMenu(char ch, arrays& a)
{
	int el;

	cout << "what you want to find?: ";
	cin >> el;

	switch (ch)
	{
	case '1': a.interpolationSearch();
	case '2': a.binaryTrackingSearch();
	}
}