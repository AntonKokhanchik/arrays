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

	//������� ���������� 

	///<summary>���������� ���������� �������</summary>
	void selectionSort();
	void insertionSort();

	//���������� ���������� �� �������

	void shakerSort();
	void combSort();

	// ������� ����������

	void quickSort();
	void piramidalSort();

	//������������� ����������

	void blockSort();
	void bitSort();

	//������

	int interpolationSearch(int);
	void binaryTrackingSearch();



};

