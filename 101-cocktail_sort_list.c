#include "sort.h"
void swap_ahead(listint_t **list, listint_t **taill, listint_t **shakr);
void swap_behind(listint_t **list, listint_t **taill, listint_t **shakr);
void cocktail_sort_list(listint_t **list);

/**
 * swap_ahead - Swap a node in a listint_t doubly   linked list
 * @list: Pointer to the  head of a doubly  linked list of integers
 * @taill: Pointer to the  taill of   doubly  linked list
 * @shakr: Pointer to the current swapping node of the cocktail shakr algo
 */
void swap_ahead(listint_t **list, listint_t **taill, listint_t **shakr)
{
	listint_t *tempo = (*shakr)->next;

	if ((*shakr)->prev != NULL)
		(*shakr)->prev->next = tempo;
	else
		*list = tempo;
	tempo->prev = (*shakr)->prev;
	(*shakr)->next = tempo->next;
	if (tempo->next != NULL)
		tempo->next->prev = *shakr;
	else
		*taill = *shakr;
	(*shakr)->prev = tempo;
	tempo->next = *shakr;
	*shakr = tempo;
}

/**
 * swap_behind - Swap a node in a listint_t doubly-linked
 * @list: Pointer to the head of a doubly   linked list of integers.
 * @taill: Pointer to the taill of the doubly   linked list.
 * @shakr: Pointer to the current swapping node of the cocktail shakr algo.
 */
void swap_behind(listint_t **list, listint_t **taill, listint_t **shakr)
{
	listint_t *tempo = (*shakr)->prev;

	if ((*shakr)->next != NULL)
		(*shakr)->next->prev = tempo;
	else
		*taill = tempo;
	tempo->next = (*shakr)->next;
	(*shakr)->prev = tempo->prev;
	if (tempo->prev != NULL)
		tempo->prev->next = *shakr;
	else
		*list = *shakr;
	(*shakr)->next = tempo;
	tempo->prev = *shakr;
	*shakr = tempo;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly   linked list of integers in
 *                      ascending order using the cocktail shakr algorithm.
 * @list: Pointer to the head of a listint_t doubly   linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *taill, *shakr;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (taill = *list; taill->next != NULL;)
		taill = taill->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shakr = *list; shakr != taill; shakr = shakr->next)
		{
			if (shakr->n > shakr->next->n)
			{
				swap_ahead(list, &taill, &shakr);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shakr = shakr->prev; shakr != *list;
				shakr = shakr->prev)
		{
			if (shakr->n < shakr->prev->n)
			{
				swap_behind(list, &taill, &shakr);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
