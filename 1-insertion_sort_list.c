#include "sort.h"
/**
 * insertion_sort_list - Function sorted the doubly linked list in ascending
 * @list: list node
 * Return: Success Always 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *f;

	if (!list || !(*list))
		return;
	i = *list;

	while (i)
	{
		f = i;
		while (f->prev && f->n < f->prev->n)
		{
			f->prev->next = f->next;

			if (f->next)
			{
				f->next->prev = f->prev;
			}

			f->next = f->prev;
			f->prev = f->prev->prev;
			f->next->prev = f;

			if (!f->prev)
				*list = f;
			else
				f->prev->next = f;
			print_list(*list);
		}
		i = i->next;
	}
}
