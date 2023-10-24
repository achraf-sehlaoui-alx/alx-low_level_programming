#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at at index
 * @head: the first node in the linked list
 * @index: index of the node to return
 *
 * Return: pointer to the node or NULL if the node is null
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *t = head;

	while (t && i < index)
	{
	t = t->next;
	i++;
	}

	if (t == NULL)
		return (NULL);

	return (t);
}
