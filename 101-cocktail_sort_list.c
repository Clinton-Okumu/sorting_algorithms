#include "sort.h"
#include <stdio.h>
/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *end = node->prev, *i = node;

	end->next = i->next;
	if (i->next)
		i->next->prev = end;
	i->next = end;
	i->prev = end->prev;
	end->prev = i;
	if (i->prev)
		i->prev->next = i;
	else
		*list = i;
	return (i);
}
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swapElements = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (swapElements == 1)
	{
		swapElements = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swapElements = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swapElements == 0)
			break;
		swapElements = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swapElements = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}