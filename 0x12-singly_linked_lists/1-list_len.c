#include <stdlib.h>
#include "lists.h"

/**
 * list_len - size of a linked list
 * @h: the first node of the list_t list
 *
 * Return: the size of the list
 */
size_t list_len(const list_t *h)
{
	size_t size = 0;

	while (h)
	{
		size++;
		h = h->next;
	}
	return (size);
}
