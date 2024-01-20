#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list
 * @list: Pointer to the pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

{
listint_t *current = (*list)->next;
listint_t *insertion;
listint_t *temp;

while (current != NULL)
{
insertion = current->prev;
temp = current;

while (insertion != NULL && insertion->n > current->n)
{
insertion->next = temp->next;
if (temp->next != NULL)
temp->next->prev = insertion;

temp->prev = insertion->prev;
temp->next = insertion;
if (insertion->prev != NULL)
insertion->prev->next = temp;
else
*list = temp;

insertion->prev = temp;

print_list(*list);

insertion = temp->prev;
}

current = current->next;
}
}
}
