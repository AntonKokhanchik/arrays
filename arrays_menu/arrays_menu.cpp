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
	} while (ch != 27 || ch < '1');

	if (ch != 27)
		executeMain(ch, a);

	return ch;
}

void printMainMenu()
{
	cout << "Press:\n"
		<< "1 to create array\n"
		<< "2 to sort array\n"
		<< "3 to find element\n";
}

void executeMain(char ch, arrays& a)
{
	switch (ch)
	{
	case '1': createArrayMenu(a); break;
	case '2': sortArrayMenu(a); break;
	case '3': findMenu(a); break;
	}
}

void createArrayMenu(arrays& a)
{
	char ch;

	printCreateArrayMenu();

	do
	{
		ch = _getch();
	} while (ch != '1' || ch != '2' || ch != 27);

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

