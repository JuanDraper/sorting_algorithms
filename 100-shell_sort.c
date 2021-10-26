#include "sort.h"
/**
* shell_sort - shell sort algoritm.
* @array: Array to sort.
* @size: Size of the array.
*/
void shell_sort(int *array, size_t size)
{
	int t;
	unsigned int k = 1, i, j, s;

	if (size < 2)
		return;
	while (k < size)
		k = k * 3 + 1;
	while (k > 1)
	{
		k = (k - 1) / 3;
		for (i = 0; i < size - 1; i++)
		{
			s = i;
			for (j = i + k; j < size; j += k)
			{
				if (array[j] < array[s])
				{
					s = j;
				}
			}
			t = array[s];
			array[s] = array[i];
			array[i] = t;
		}
		print_array(array, size);
	}
}
