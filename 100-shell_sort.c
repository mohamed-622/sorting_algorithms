#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 *              Shell sort algorithm with Knuth sequence.
 *
 * @array: Pointer to the first element of the array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	/* Find the initial gap using Knuth sequence */
	while (gap < size)
		gap = gap * 3 + 1;

	/* Reduce the gap using Knuth sequence and perform insertion sort */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}

			array[j] = temp;
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
