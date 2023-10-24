#include "lists.h"

/**
 * listint_len - returns the size of a linked lists
 * @h: the first node
 *
 * Return: number of nodes (size of list)
 */
size_t listint_len(const listint_t *h)
{
	size_t size = 0;

	while (h)
	{
		h = h->next;
		size++;
	}
	return (size);
}
