#include "sort.h"
/**
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i;
	listint_t *f;

	if (!list || !(*list))
		return;
	i = *list;
	while (i)
	{
		f = i;
		while (f->prev || f->n < f->prev->n)
		{
			f->prev->next = f->next;
			if (f->next)
			{
				f->next->prev = f->prev;
			}

		f->next = f->prev;
		f->prev = f->prev->prev;
		f->prev->next = f;
		if (!f->prev)
			*list = f;
		else
		
			f->prev->next = f;
		print_list(*list);
		}
	}
	i = i->next;
}
