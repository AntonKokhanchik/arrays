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

	void interpolationSearch();
	void binaryTrackingSearch();


	void quickSortRecurs(int*, int);

};

