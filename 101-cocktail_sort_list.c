#include "sort.h"

/**
 * lastNode - last node of
 * @head: Head of the list
 * Return: pointer to last node
 */
listint_t *lastNode(listint_t *head)
{
	listint_t *ptr = head;

	while (ptr->next != NULL)
		ptr = ptr->next;

	return (ptr);
}

/**
 * swinger - exchanges two doubly linked nodes together
 * @left: left node
 * @right: right node
 * @head: Head of the list
 * Return: void
 */
listint_t *swinger(listint_t *left, listint_t *right, listint_t *head)
{
	listint_t *t;

	if (right->next)
		right->next->prev = left;
	if (left->prev)
		left->prev->next = right;

	right->prev = left->prev;
	left->next = right->next;
	right->next = left;
	left->prev = right;

	t = left;
	left = right;
	right = t;

	if (left->prev == NULL)
		return (left);
	else
		return (head);
}

/**
 * BootyShakeUp - Runs a bubblesort forward
 * @left: left node
 * @right: right node
 * @head: head of the list
 * Return: result struct with status and new head
 */
outcome BootyShakeUp(listint_t *left, listint_t *right, listint_t *head)
{
	listint_t *nr;
	outcome s;

	s.status = 0;
	s.head = head;

	if (left == right)
		return (s);

	nr = left->next;
	while (left != right)
	{
		if (left->n > nr->n)
		{
			head = swinger(left, nr, head);
			print_list(head);
			s.status = 1;
			s.head = head;
		}
		left = nr;
		nr = nr->next;
	}
	return (s);
}

/**
 * BootyShakeDown - Runs a bubblesort backwards
 * @left: left node
 * @right: right node
 * @head: head of the list
 * Return: result struct with status and new head
 */
outcome BootyShakeDown(listint_t *left, listint_t *right, listint_t *head)
{
	listint_t *nr;
	outcome s;

	s.status = 0;
	s.head = head;

	if (left == right)
		return (s);

	nr = right->prev;
	while (right != left)
	{
		if (right->n < nr->n)
		{
			head = swinger(nr, right, head);
			print_list(head);
			s.status = 1;
			s.head = head;
		}
		right = nr;
		nr = nr->prev;
	}
	return (s);
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: head of the list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t  *left, *right;
	outcome s;

	if (!list || !*list || !(*list)->next)
		return;

	left = *list;
	right = lastNode(*list);
	s.status = 0;
	s.head = *list;

	do {
		s = BootyShakeUp(left, right, s.head);
		left = s.head;
		right = lastNode(left);
		s = BootyShakeDown(left, right, s.head);
		left = s.head;
		right = lastNode(left);
	} while (s.status == 1);

	*list = s.head;
}
