#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swapping(int *array, __ssize_t item, __ssize_t item1);
void quick_sort(int *array, size_t size);
void recursive_quick(int *array, int start, int end, size_t size);
__ssize_t array_partition(int *arr, __ssize_t start, __ssize_t end, size_t array_size);
void shell_sort(int *arr, size_t size);
void swap(listint_t **list, listint_t *left, listint_t *right);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void *_calloc(unsigned int nmemb, unsigned int size);
void PrintArray(int *arr, int first, int end);
void CopyArray(int *source, int first, int end, int *station);
void TopDownMerge(int *source, int first, int center, int end, int *station);
void TopDownSplitMerge(int *source, int first, int end, int *station);
void merge_sort(int *array, size_t size);


#endif
