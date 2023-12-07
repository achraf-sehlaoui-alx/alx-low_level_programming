#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: the head of the list
 * @n: n of the new node
 * Return: address of the new element or NULL
 **/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;

	if (*head)
	{
		while ((*head)->next)
			*head = (*head)->next;
		new->prev = *head;
		(*head)->next = new;
	}
	else
	{
		*head = new;
		new->prev = NULL;
	}

	return (new);
}
