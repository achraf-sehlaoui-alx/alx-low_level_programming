#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node node at a given position
 * in a dlistint_t list.
 * @h: pointer to the list.
 * @idx: position to add the node.
 * @n: data for the new node.
 * Return: the address of the new node, or NULL if it failed
 **/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp = *h, *new;
	unsigned int index, cont = 0;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;

	if (idx == 0)
	{
		new->prev = NULL;
		new->next = *h;
		if (*h)
			(*h)->prev = new;
		*h = new;
		return (*h);
	}

	index = idx - 1;
	while (tmp && cont != index)
	{
		cont++;
		tmp = tmp->next;
	}

	if (cont == index && tmp)
	{
		new->prev = tmp;
		new->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = new;
		tmp->next = new;
		return (new);
	}
	free(new);
	return (NULL);
}
