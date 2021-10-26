#include "sort.h"
/**
* counting_sort - counting sort algorithm.
* @array: Array to sort.
* @size: Size of the array.
*/
void counting_sort(int *array, size_t size)
{
	unsigned int i, b = 0;
	int *c, *o;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
		if ((unsigned int)array[i] > b)
			b = array[i];
	c = malloc((b + 1) * sizeof(int));
	if (!c)
		return;
	for (i = 0; i <= b; i++)
		c[i] = 0;
	for (i = 0; i < size; i++)
		c[array[i]]++;
	for (i = 1; i <= b; i++)
		c[i] += c[i - 1];
	print_array(c, b + 1);
	o = malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
		o[--c[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = o[i];
	free(c);
	free(o);
}
