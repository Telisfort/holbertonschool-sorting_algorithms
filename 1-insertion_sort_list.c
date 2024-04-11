#include "sort.h"

/**
 * insertion_sort_list - trie une liste doublement chaînée d'entiers
 * par ordre croissant en utilisant l'algorithme de tri par insertion
 * @list: liste doublement chaînée
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prevprev, *prevv, *curr1, *currnext;

	if (list == NULL)
		return;

	curr = *list;

	while (curr)
	{
		if (curr->prev && curr->prev->n > curr->n)
		{
			prevprev = curr->prev->prev;
			prevv = curr->prev;
			curr1 = curr;
			currnext = curr->next;
			prevv->next = currnext;

			if (currnext)
				currnext->prev = prevv;

			curr1->prev = prevprev;
			curr1->next = prevv;

			if (prevprev)
				prevprev->next = curr1;

			else
				*list = curr1;

			prevv->prev = curr1;
			curr = *list;
			print_list(*list);
			continue;
		}
		else
			curr = curr->next;
	}
}

