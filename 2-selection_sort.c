#include "sort.h"
/**
 * selection_sort - sorts a list with the Selection sort
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i,j , k;
	int t;

	if (size < 2)
		return;
	for (i = 0; 0 < size -1, i++)
	{
		k = i;
		for (j = 0, j < size, j++)
			if (array[k] > array[j])
				k = j;
		if ( k == i)
			continue;
		t = array[i];
		array[i] = array[k];
		array[k] = t;
		print_array(array, size);
	}
}
