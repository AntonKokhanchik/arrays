#pragma once
class arrays
{
private:
	int* arr;
	int length;
	int hunt;

	void quickSortRecurs(int, int);
	void shiftDown(int, int);
	int binarySearch(int, int, int);
public:
	arrays();
	arrays(int);
	~arrays();

	///<summary>���������� ���������� �������� ��������</summary>
	int Length() { return length; }

	///<summary>������������������ ������ � ����� �������� ������, ������ ����� ������</summary>
	void reinit(int);

	///<summary>���������� ������� ������� �� ��������� �������</summary>
	int& operator[] (int);

	//������� ���������� 

	///<summary>���������� ���������� �������</summary>
	void selectionSort();
	///<summary>���������� ���������� ���������</summary>
	void insertionSort();

	//���������� ���������� �� �������

	///<summary>���������� ��������� ����������</summary>
	void shakerSort();
	///<summary>���������� ���������� �������������</summary>
	void combSort();

	// ������� ����������

	///<summary>���������� ������� ����������</summary>
	void quickSort();
	///<summary>���������� �����������������������</summary>
	void piramidalSort();

	//������������� ����������

	///<summary>���������� �������� (���������), ����� �����������</summary>
	void blockSort();
	///<summary>���������� ������� ���������� - �������� �������</summary>
	void bitSort();

	//������

	///<summary>���������� ��������������� �����</summary>
	int interpolationSearch(int);
	///<summary>���������� �������� �������� �����</summary>
	int binaryTrackingSearch(int);
};

