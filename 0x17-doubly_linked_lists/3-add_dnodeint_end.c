#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: the head of the list
 * @n: n of the new node
 * Return: address of the new element or NULL
 **/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t)), *node;

	if (!new || !head)
		return (new ? free(new), NULL : NULL);
	new->n = n;
	new->next = NULL;

	if (*head)
	{
		node = *head;
		while (node->next)
			node = node->next;
		new->prev = node;
		node->next = new;
	}
	else
	{
		*head = new;
		new->prev = NULL;
	}

	return (new);
}
