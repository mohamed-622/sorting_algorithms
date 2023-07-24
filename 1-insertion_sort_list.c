#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm.
 *
 * @list: Pointer to the first node of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		temp = current->prev;

		while (temp != NULL && temp->n > current->n)
		{
			temp->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp;

			current->next = temp;
			current->prev = temp->prev;

			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;

			temp->prev = current;
			temp = current->prev;

			print_list(*list);
		}

		current = next_node;
	}
}
