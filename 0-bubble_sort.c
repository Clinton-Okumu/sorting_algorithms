#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 *@array: array to be sorted
 *@size: size of the array
 *Return: array sorted
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int temp;
int swap;

if (array == NULL || size < 2)
return;

for (i = 0; i < size - 1; i++)
{
swap = 0;

for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;

swap = 1;
print_array(array, size);
}
}
if (swap == 0)
break;
}
}
