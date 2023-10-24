#include "lists.h"

/**
 * print_listint - prints a linked list
 * @h: the first node
 *
 * Return: number of nodes (size of list)
 */

size_t print_listint(const listint_t *h)
{
	size_t size = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		size++;
	}

	return (size);
}
