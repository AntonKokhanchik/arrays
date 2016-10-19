// arrays_menu.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "arrays.h"
#include "conio.h"
#include "iostream"
#include "time.h"
#include "windows.h"

using namespace std;

typedef void (arrays:: *sort)();
typedef int (arrays:: *search)(int);

char mainMenu(char ch, arrays& a);
void printMainMenu();
void executeMainMenu(char ch, arrays& a);
void createArrayMenu(arrays& a);
void printCreateArrayMenu();
void executeCreateArrayMenu(char ch, arrays& a);
void createArrayManually(arrays& a);
void createRandomArray(arrays& a);
void sortArrayMenu(arrays& a);
void sortArrayMenu(arrays& a);
void printSortArrayMenu();
void executeSortArrayMenu(char ch, arrays& a);
void searchMenu(arrays& a);
void printSearchMenu();
void executeSearchMenu(char ch, arrays& a);
void printArray(arrays& a);
void sortTimer(char* str, sort f, arrays& a);
int searchTimer(int ask, char* str, search f, arrays& a);

int main()
{
	char ch = 0;
	arrays a;

	do
	{
		ch = mainMenu(ch, a);
	} while (ch != 27);

	return 0;
}
//
char mainMenu(char ch, arrays& a)
{
	printMainMenu();

	do {
		ch = _getch();
	} while (ch != 27 && (ch < '1' || ch > '4'));

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
		<< "4 to print array\n"
		<< "esc to exit";
	cout << "\n\n";
}

void executeMainMenu(char ch, arrays& a)
{
	switch (ch)
	{
	case '1': createArrayMenu(a); break;
	case '2': sortArrayMenu(a); break;
	case '3': searchMenu(a); break;
	case '4': printArray(a); break;
	}
}
//
void createArrayMenu(arrays& a)
{
	char ch;

	printCreateArrayMenu();

	do
	{
		ch = _getch();
	} while (ch != 27 && (ch < '1' || ch > '2'));

	if (ch != 27)
		executeCreateArrayMenu(ch, a);
}

void printCreateArrayMenu()
{
	cout << "Press:\n"
		<< "1 to to create array manually\n"
		<< "2 to create random array\n"
		<< "esc to cancel";
	cout << "\n\n";
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

	cout << "\n\n";
	cout << "Manual array creation\n";
	cout << "Enter length: ";
	cin >> l;
	a.reinit(l);

	cout << "enter elements:\n";
	for (int i = 0; i < l; i++)
		cin >> a[i];
	cout << "\n\n";
}

void createRandomArray(arrays& a)
{
	srand(time(NULL));
	int l;

	cout << "\n\n";
	cout << "Random array creation\n";
	cout << "Enter length: ";
	cin >> l;
	a.reinit(l);

	for (int i = 0; i < l; i++)
		a[i] = rand() % 10000;
	cout << "\n\n";
}
//
void sortArrayMenu(arrays& a)
{
	char ch;

	printSortArrayMenu();

	do
	{
		ch = _getch();
	} while (ch != 27 && (ch < '1' || ch > '8'));

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
	cout << "\n\n";
}

void executeSortArrayMenu(char ch, arrays& a)
{
	switch (ch)
	{
	case '1': sortTimer("selection sort", &arrays::selectionSort, a); break;
	case '2': sortTimer("insertion sort", &arrays::insertionSort, a); break;
	case '3': sortTimer("shaker sort", &arrays::shakerSort, a); break;
	case '4': sortTimer("comb sort", &arrays::combSort, a); break;
	case '5': sortTimer("quick sort", &arrays::quickSort, a); break;
	case '6': sortTimer("piramidal sort", &arrays::piramidalSort, a); break;
	case '7': sortTimer("block sort", &arrays::blockSort, a); break;
	case '8': sortTimer("bit sort", &arrays::bitSort, a); break;
	}
}
//
void searchMenu(arrays& a)
{
	char ch;

	printSearchMenu();

	do
	{
		ch = _getch();
	} while (ch != 27 && (ch < '1' || ch > '2'));

	if (ch != 27)
		executeSearchMenu(ch, a);
}

void printSearchMenu()
{
	cout << "press to execute:\n"
		<< "1 - interpolation search\n"
		<< "2 - binary tracking search\n"
		<< "esc to cncel";
	cout << "\n\n";
}

void executeSearchMenu(char ch, arrays& a)
{
	int ask, answer;

	cout << "Searching\n";
	cout << "what you want to find?: ";
	cout << "\n\n";
	cin >> ask;

	switch (ch)
	{
	case '1': answer = searchTimer(ask, "interpolation search", &arrays::interpolationSearch, a); break;
	case '2': answer = searchTimer(ask, "binary tracking search", &arrays::binaryTrackingSearch, a); break;
	}

	if (answer == -1)
		cout << "no asking element in array";
	else
		cout << "asking element is a number " << answer << " in array";
	
	cout << "\n\n";
}
//
void printArray(arrays& a)
{
	for (int i = 0; i < a.Length(); i++)
		cout << a[i] << "  ";

	cout << "\n\n";
}

void sortTimer(char* str, sort f, arrays& a)
{
	int start, stop;

	cout << "doing " << str << ":\n";
	start = GetTickCount();
	(a.*f)();
	stop = GetTickCount();
	cout << "done with " << stop - start << " ticks";
	cout << "\n\n";
}

int searchTimer(int ask, char* str, search f, arrays& a)
{
	int start, stop, answer;

	cout << "doing " << str << ":\n";
	start = GetTickCount();
	answer = (a.*f)(ask);
	stop = GetTickCount();
	cout << "done with " << stop - start << " ticks";
	cout << "\n\n";
	return answer;
}