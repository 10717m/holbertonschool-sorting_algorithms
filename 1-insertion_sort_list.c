#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;
while (current != NULL)
{
temp = current;
current = current->next;
while (temp->prev != NULL && temp->n < temp->prev->n)
{
/* Swap nodes */
temp->prev->next = temp->next;
if (temp->next != NULL)
temp->next->prev = temp->prev;
temp->next = temp->prev;
temp->prev = temp->prev->prev;
temp->next->prev = temp;
if (temp->prev == NULL)
*list = temp;
else
temp->prev->next = temp;
print_list(*list);
}
}
}
