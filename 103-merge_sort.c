#include <stdio.h>
#include "sort.h"

/**
 * merge - merge function
 * @array: pointer to array
 * @size: size of the array
 * @left: pointer to left array
 * @right: pointer to right array
 * Return: void
 **/
void merge(int *array, int *left, int *right, size_t size)
{
	int i, j, k, lsize, rsize;

	lsize = size / 2;
	rsize = size - lsize;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, lsize);
	printf("[right]: ");
	print_array(right, rsize);

	i = 0;
	j = 0;
	k = 0;

	while (i < lsize && j < rsize)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < lsize)
		array[k++] = left[i++];

	while (j < rsize)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - merge sort
 * @array: array to be evaluated
 * @size: array size
 * Return: void
 **/
void merge_sort(int *array, size_t size)
{
	size_t m;
	size_t i;
	int p[1024];
	int *left;
	int *right;

	if (array == NULL || size < 2)
		return;

	m = size / 2;
	left = p;
	right = &p[m];

	for (i = 0; i < m; i++)
		left[i] = array[i];

	for (i = m; i < size; i++)
		right[i - m] = array[i];

	merge_sort(left, m);
	merge_sort(right, size - m);
	merge(array, left, right, size);
}
