#include "sort.h"
/**
* bubble_sort - Implementation of the bubble sort algorithm.
* @array: array to sort.
* @size: Size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	int n = size - 1, i, tmp;
	char sw;

	if (size < 2)
		return;
	do {
		sw = 0;
		for (i = 0; i < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				sw = 1;
				print_array(array, size);
			}
		}
		n -= 1;
	} while (sw);
}
