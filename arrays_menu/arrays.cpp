#include "arrays.h"


arrays::arrays(int size)
{
	length = size;
	arr = new int[size];
}

arrays::~arrays()
{
	delete[] arr;
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
			tmp = i;
			i = min;
			min = tmp;
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
}

void arrays::combSort()
{
	for (int step = int(length / 1.3); step >= 1; step = int(step / 1.3))
	{
		if (step == 9 || step == 10)
			step = 11;

		for (int i = 0; i < step; i++)
		{
			int tmp = arr[i];
			for (int j = i + step; j < length - 1; j += step)
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

void arrays::quickSort()
{
	quickSortRecurs(arr, length);
}

void arrays::quickSortRecurs(int* a, int l)
{
	int sum;
	for (int i = 0; i < length - 1; i++)
	{
		sum += arr[i];
	}
	int middle = int(sum / length);


}