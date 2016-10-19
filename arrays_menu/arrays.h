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

	///<summary>Возвращает количество символов вмвссиве</summary>
	int Length() { return length; }

	///<summary>Переинициализирует массив с новой заданной длиной, массив будет пустым</summary>
	void reinit(int);

	///<summary>Возвращает элемент массива по заданному индексу</summary>
	int& operator[] (int);

	//базовые сортировки 

	///<summary>производит сортировку выбором</summary>
	void selectionSort();
	///<summary>производит сортировку вставками</summary>
	void insertionSort();

	//сортировки основанные на базовых

	///<summary>производит шейкерную сортировку</summary>
	void shakerSort();
	///<summary>производит сортировку прочёсыванием</summary>
	void combSort();

	// быстрые сортировки

	///<summary>производит быструю сортировку</summary>
	void quickSort();
	///<summary>производит пирамидальнуюсортировку</summary>
	void piramidalSort();

	//целочисленные сортировки

	///<summary>производит блоковую (корзинную), здесь поразрядную</summary>
	void blockSort();
	///<summary>производит битовую сортировку - блоковую побитно</summary>
	void bitSort();

	//поиски

	///<summary>производит интерполяционый поиск</summary>
	int interpolationSearch(int);
	///<summary>производит двоичный следящий поиск</summary>
	int binaryTrackingSearch(int);
};

