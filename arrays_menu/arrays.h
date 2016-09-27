#pragma once
class arrays
{
private:
	int* arr;
	int length;

public:
	arrays(int);
	~arrays();

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

