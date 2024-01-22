#include "sort.h"
/**
 * swapping - swaps two elements in an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swapping(int *array, __ssize_t item, __ssize_t item1)
{
int tmp;

tmp =  array[item];
array[item] = array[item1];
array[item1] = tmp;
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
__ssize_t array_partition(int *arr, __ssize_t start, __ssize_t end, size_t array_size)
{
int pivot = arr[end];
__ssize_t current = start, j;

for (j = start; j <= end; j++)
{
if (arr[j] < pivot)
{
if (arr[current] != arr[j])
{
swapping(arr, current, j);
print_array(arr, array_size);
}
current++;
}
}
if (arr[current] != arr[end])
{
    swapping(arr, current, end);
    print_array(arr, array_size);
}
return (current);
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
