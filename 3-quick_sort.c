#include "sort.h"
/**
 * swapping - swaps two elements in an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swapping(int *a, int *b)
{
if (a != b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}
}

/**
 * array_partition - partition scheme for quicksort
 * @arr: array to be sorted
 * @start: starting index of the partition
 * @end: ending index of the partition
 * @array_size: size of the array
 *
 * Return: index of the pivot element
 */
size_t array_partition(int *arr, int start, int end, size_t array_size)
{
int pivot = arr[end];
int i = start - 1;
int j;

for (j = start; j <= end - 1; j++)
{
if (arr[j] < pivot)
{
i++;
swapping(&arr[i], &arr[j]);
print_array(arr, array_size);
}
}
swapping(&arr[i + 1], &arr[end]);
print_array(arr, array_size);

return (i + 1);
}

/**
 * recursive_quick - recursive function for quicksort
 * @array: array to be sorted
 * @start: starting index of the partition
 * @end: ending index of the partition
 * @size: size of the array
 */
void recursive_quick(int *array, int start, int end, size_t size)
{
size_t pivot;

if (start < end)
{
pivot = array_partition(array, start, end, size);

recursive_quick(array, start, pivot - 1, size);
recursive_quick(array, pivot + 1, end, size);
}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

recursive_quick(array, 0, size - 1, size);
}
