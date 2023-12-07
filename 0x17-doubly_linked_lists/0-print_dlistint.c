#include "lists.h"

/**
 * print_dlistint - prints of a dlistint_t list
 * @h: pointer to the head of the list
 * Return: size of the list
 **/
size_t print_dlistint(const dlistint_t *h)
{
	size_t z = 0;

	while (h)
	{
		printf("%d\n", h->n);
		z++;
		h = h->next;
	}

	return (z);
}
