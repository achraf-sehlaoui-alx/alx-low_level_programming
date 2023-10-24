#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a list at index
 * @head: pointer to the first node
 * @index: index of the node to delete
 *
 * Return: 1 on (Success), or -1 on (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *t = *head;
	listint_t *c = NULL;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	if (!index)
	{
		*head = (*head)->next;
		free(t);
		return (1);
	}

	while (i < index - 1)
	{
		if (!t || !(t->next))
			return (-1);
		t = t->next;
		i++;
	}


	c = t->next;
	t->next = c->next;
	free(c);

	return (1);
}
