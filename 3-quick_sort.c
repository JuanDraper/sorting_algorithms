#include "sort.h"

/**
 * swinger - exchanges two array pointers
 * @left: A pointer
 * @right: Another pointer
 * Return: void
 */
void swinger(int *left, int *right)
{
	int t;

	t = *left;
	*left = *right;
	*right = t;
}

/**
 * partScheme - Lomuto's partition
 * @array: Array to be parted
 * @size: size of the whole array
 * @left: start index
 * @right: end index
 * Return: Index to use as partition
 */
int partScheme(int *array, int size, int left, int right)
{
	int p, pi, j;

	p = array[right];
	pi = left;

	for (j = left; j < right; j++)
	{
		if (array[j] <= p)
		{
			swinger(&array[pi], &array[j]);
			if (pi != j)
				print_array(array, size);
			pi++;
		}
	}
	swinger(&array[pi], &array[right]);
	if (pi != j)
		print_array(array, size);
	return (pi);
}

/**
 * lqs - Lomuto implementation of Quicksort
 * @array: Array to be sorted
 * @size: size of the whole array
 * @left: start index
 * @right: end index
 * Return: void
 */
void lqs(int *array, int size, int left, int right)
{
	int p;

	if (left < right)
	{
		p = partScheme(array, size, left, right);
		lqs(array, size, left, p - 1);
		lqs(array, size, p + 1, right);
	}

}

/**
 * quick_sort - quicksort of array
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	lqs(array, size, 0, size - 1);
}

