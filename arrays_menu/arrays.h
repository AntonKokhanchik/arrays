#pragma once
class arrays
{
private:
	int* arr;
	int length;

	void quickSortRecurs(int, int);
	void shiftDown(int, int);
public:
	arrays();
	arrays(int);
	~arrays();

	int Length() { return length; }

	void reinit(int);

	int& operator[] (int);

	//базовые сортировки 

	///<summary>производит сортировку выбором</summary>
	void selectionSort();
	void insertionSort();

	//сортировки основанные на базовых

	void shakerSort();
	void combSort();

	// быстрые сортировки

	void quickSort();
	void piramidalSort();

	//целочисленные сортировки

	void blockSort();
	void bitSort();

	//поиски

	int interpolationSearch(int);
	void binaryTrackingSearch();



};

