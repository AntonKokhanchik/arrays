#pragma once
class arrays
{
private:
	int* arr;
	int length;

public:
	arrays();
	arrays(int);
	~arrays();

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

	void interpolationSearch();
	void binaryTrackingSearch();


	void quickSortRecurs(int*, int);

};

