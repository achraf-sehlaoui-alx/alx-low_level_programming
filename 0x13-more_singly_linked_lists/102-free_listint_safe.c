#include "lists.h"

/**
 * free_listint_safe - free a linked list in a safe way
 * @h: the first node in the list
 *
 * Return: size of the list that it free
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	int i;
	listint_t *t;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		i = *h - (*h)->next;
		if (i > 0)
		{
			t = (*h)->next;
			free(*h);
			*h = t;
			size++;
		}
		else
		{
			free(*h);
			*h = NULL;
			size++;
			break;
		}
	}

	*h = NULL;

	return (size);
}
