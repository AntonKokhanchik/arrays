#include "stdafx.h"
#include "arrays.h"

arrays::arrays()
{
	length = 0;
	arr = NULL;
}

arrays::arrays(int size)
{
	length = size;
	arr = new int[size];
}

arrays::~arrays()
{
	delete[] arr;
}

void arrays::reinit(int size)
{
	delete[] arr;
	length = size;
	arr = new int[size];
}

int& arrays::operator[] (int i)
{
	return arr[i];
}

//базовые сортировки

void arrays::selectionSort()
{
	int min;
	int tmp;

	for (int i = 0; i < length - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i)
		{
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}

void arrays::insertionSort()
{
	for (int i = 1; i < length; i++)//поиск элемента для вставки
	{
		int tmp = arr[i];			//запоминаем значение
		int j = i - 1;				//индекс для поиска места вставки

		for (; (j >= 0 && arr[j] > tmp); j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = tmp;
	}
}

//сортировки основанные на базовых

void arrays::shakerSort()
{
	for (int left = 0, right = length - 1, k = 0; left < right; k++)
	{
		while (arr[left] < arr[left + 1])
			left++;

		int bubble = arr[left];

		for (int i = left + 1; i < length - 1 - k; i++)
			if (arr[i] < bubble)
				arr[i - 1] = arr[i];
			else
			{
				arr[i - 1] = bubble;
				bubble = arr[i];
			}

		while (arr[right] > arr[right - 1])
			right--;

		bubble = arr[right];

		for (int i = right - 1; i > k; i--)
			if (arr[i] > bubble)
				arr[i + 1] = arr[i];
			else
			{
				arr[i + 1] = bubble;
				bubble = arr[i];
			}
	}
}		//исправить

void arrays::combSort()
{
	for (int step = int(length / 1.3); step >= 1; step = int(step / 1.3))
	{
		if (step == 9 || step == 10)
			step = 11;

		for (int i = 0; i < step; i++)
		{
			int tmp = arr[i];
			for (int j = i + step; j < length; j += step)
			{
				if (tmp > arr[j])
				{
					arr[j - step] = arr[j];
				}
				else
				{
					arr[j - step] = tmp;
					tmp = arr[j];
				}
				if (j + step > length - 1)
					arr[j] = tmp;
			}
		}
	}
}

// быстрые сортировки

void arrays::quickSort()
{
	quickSortRecurs(0, length-1);
}

void arrays::quickSortRecurs(int min, int max)
{
	int middle, h, l;

	if (max - min <= 10)
	{
		for (int i = min; i <= max; i++)
		{
			int tmp = arr[i];
			int j = i - 1;

			for (; (j >= 0 && arr[j] > tmp); j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = tmp;
		}
		return;
	}

	middle = arr[min];
	l = min;
	h = max;

	while (true)
	{
		while (arr[h] >= middle)
		{
			h--;
			if (h <= l)
				break;
		}
		if (h <= l)
		{
			arr[l] = middle;
			break;
		}
		arr[l] = arr[h];
		l++;
		while (arr[l] < middle)
		{
			l++;
			if (l >= h)
				break;
		}
		if (l >= h)
		{
			l = h;
			arr[h] = middle;
			break;
		}
		arr[h] = arr[l];
	}
	quickSortRecurs(min, l - 1);
	quickSortRecurs(l + 1, max);
}

void arrays::piramidalSort()
{
	for (int i = (length / 2) - 1; i > -1; i--)
		shiftDown(i, length);

	for (int i = length - 1; i > 0; i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		shiftDown(0, i);
	}
}

void arrays::shiftDown(int i, int j)
{
	int max;
	bool isDone = false;

	while (2*i+1 < j && !isDone)
	{
		if (2*i+1 == j-1 || arr[2*i+1] > arr[2*i+2])
			max = 2*i+1;
		else
			max = 2*i+2;

		if (arr[i] < arr[max])
		{
			int tmp = arr[i];
			arr[i] = arr[max];
			arr[max] = tmp;
			i = max;
		}
		else
			isDone = true;
	}
}

//целочисленные сортировки

void arrays::blockSort() //есть проблема
{
	int** bucket = new int* [10];
	for(int i=0;i<10;i++)
		bucket[i] = new int[length];

	for (int k = 1; k <= 100000; k *= 10)
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < length; j++)
				bucket[i][j] = -1;

		int count = 0;

		for (int i = 0; i < length; i++)
		{
			int tmp = (arr[i] / k) % 10;
			bucket[tmp][i] = arr[i];//здесь плохо, не сортирует совсем из-за этого
		}

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < length; j++)
				if (bucket[i][j] == -1)
					break;
				else
				{
					arr[count] = bucket[i][j];
					count++;
				}
	}
	for (int i = 0; i < 10; i++)
		delete[] bucket[i];
	delete[] bucket;
}

void arrays::bitSort() //почему-то не работает с двузначными
{
	//n >> p & 1           p бит числа n 
	int* tmp = new int[length]; //карман
	for (int i = 0; i < sizeof(int); i++)
	{
		int zeroPtr = 0, onePtr = length - 1; //указатели на места для вставки

		for (int j = 0; j < length; j++) //распределение
		{
			if (((arr[j] >> i) & 1) == 0)
			{
				tmp[zeroPtr] = arr[j];
				zeroPtr++;
			}
			else
			{
				tmp[onePtr] = arr[j];
				onePtr--;
			}
		}

		int k = 0;                        //сборка

		for (int j = 0; j < zeroPtr; j++)
		{
			arr[k] = tmp[j];
			k++;
		}
		
		for (int j = length - 1; j > onePtr; j--)
		{
			arr[k] = tmp[j];
			k++;
		}
	}
}

