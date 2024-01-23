#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * PrintArray - prints array of integers for range of indicies
 * @array: array of values to be printed
 * @first: starting index value
 * @end: ending index value
 */
void PrintArray(int *arr, int first, int end)
{
	int i;

	for (i = first; i < end; i++)
		if (i < end - 1)
			printf("%i, ", arr[i]);
		else
			printf("%i\n", arr[i]);
}

/**
 * CopyArray - simple 1 for 1 copy of source[] to dest[]
 * @source: array of values to be sorted
 * @first: starting index value
 * @end: ending index value
 * @station: array to store sorted integers
 */
void CopyArray(int *source, int first, int end, int *station)
{
	int i;

	for (i = first; i < end; i++)
		station[i] = source[i];
}

/**
 * TopDownMerge - sorts subsections ("runs") of source[] by ascending value
 * @source: array of values to be sorted
 * @first: left run starting index value
 * @center: right run starting index value
 * @end: right run ending index value
 * @station: array to store sorted integers
 */
void TopDownMerge(int *source, int first, int center, int end, int *station)
{
	int i, j, k;

	i = first, j = center;

	printf("Merging...\n");
	printf("[left]: ");
	PrintArray(source, first, center);
	printf("[right]: ");
	PrintArray(source, center, end);
	/* While there are elements in the left or right runs... */
	for (k = first; k < end; k++)
	{
		/* If left run head exists and is <= existing right run head */
		if (i < center && (j >= end || source[i] <= source[j]))
		{
			station[k] = source[i];
			i++;
		}
		else
		{
			station[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	PrintArray(station, first, end);
}

/**
 * TopDownSplitMerge - recursive engine of merge_sort, splits working copy of
 * array into left and right runs, then merges with TopDownMerge
 * @source: array of integers to be sorted
 * @first: starting index value
 * @end: ending index value
 * @station: array to store sorted integers
 */
void TopDownSplitMerge(int *source, int first, int end, int *station)
{
	int center;

	if (end - first < 2) /* if run size == 1 */
		return;     /* consider it sorted */
	/* split the run longer than 1 item into halves */
	center = (end + first) / 2;

	TopDownSplitMerge(station, first, center, source);  /* sort left run */
	TopDownSplitMerge(station, center, end, source);  /* sort right run */
	/* merge the resulting runs from array[] into work_copy[] */
	TopDownMerge(source, first, center, end, station);
}

/**
 * merge_sort - sorts an array of integers in ascending order using a
 * top-down merge sort algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void merge_sort(int *array, size_t size)
{
	int *w_copy;

	if (!array || size < 2)
		return;

	w_copy = malloc(sizeof(int) * size);
	if (!w_copy)
		return;

	CopyArray(array, 0, size, w_copy);
	TopDownSplitMerge(w_copy, 0, size, array);

	free(w_copy);
}
