#include "sort.h"
/**
 * insertion_sort_list - sort a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: doubly linked list of integers
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *j, *tempo, *curro;

	if (!list || !*list || !(*list)->next)
		return;

	curro = (*list)->next;
	while (curro)
	{
		j = curro;
		while (j->prev && j->n < j->prev->n)
		{
			tempo = j->prev;
			if (tempo->prev)
				tempo->prev->next = j;
			j->prev = tempo->prev;
			tempo->prev = j;
			tempo->next = j->next;
			if (j->next)
				j->next->prev = tempo;
			j->next = tempo;

			if (!j->prev)
				*list = j;
			print_list(*list);
		}
		curro = curro->next;
	}
}
