#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order using a
 * counting sort algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void counting_sort(int *array, size_t size)
{
	int i, j, max;
	int *count, *result;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = calloc((max + 1), sizeof(int));
	if (!count)
		return;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 0, j = 0; i < max + 1; i++)
	{
		j = count[i] + j;
		count[i] = j;
	}
	print_array(count, max + 1);

	result = malloc(sizeof(int) * size);
	if (!result)
		return;

	for (i = 0; i < (int)size; i++)
	{
		result[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = result[i];
	free(count);
	free(result);
}