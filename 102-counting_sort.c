#include "sort.h"

/**
 * counting_sort - sort an array using counting sort algorithm
 * @array: the list to be sorted
 * @size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	size_t s;
	int max = 0, i, n;
	int *a, *count;

	if (size <= 1)
	{
		return;
	}
	count = malloc(sizeof(int) * size);
	for (s = 0; s < size; s++)
	{
		if (array[s] > max)
			max = array[s];
		count[s] = array[s];
	}
	a = malloc(sizeof(int) * (max + 1));
	if (a == NULL || count == NULL)
		return;
	for (i = 0; i < max + 1; i++)
	{
		a[i] = 0;
	}
	for (s = 0; s < size; s++)
	{
		a[array[s]]++;
	}
	for (i = 1; i < max + 1; i++)
	{
		a[i] += a[i - 1];
	}
	for (s = 0; s < size; s++)
	{
		n = a[count[s]] - 1;
		array[n] = count[s];
	}
	print_array(a, max + 1);
	free(a);
	free(count);
}
