#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort
 *
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *key;

	current = (*list)->next;

	while (current != NULL)
	{
		key = current;
		current = current->next;

		while (key->prev != NULL && key->n < key->prev->n)
		{
			/* Swap key and its previous node */
			if (key->next != NULL)
				key->next->prev = key->prev;
			key->prev->next = key->next;
			key->next = key->prev;
			key->prev = key->prev->prev;
			key->next->prev = key;

			/* Update the head of the list if needed */
			if (key->prev == NULL)
				*list = key;
			else
				key->prev->next = key;

			/* Print the list after each swap */
			print_list(*list);
		}
	}
}
