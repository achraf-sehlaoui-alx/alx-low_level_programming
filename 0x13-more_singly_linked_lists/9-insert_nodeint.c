#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given idx
 * @head: pointer to the first node
 * @idx: index of the new node
 * @n: data of the new node
 *
 * Return: pointer of new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *t = *head;

	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (!idx)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; t && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new->next = t->next;
			t->next = new;
			return (new);
		}
		else
			t = t->next;
	}

	return (NULL);
}
