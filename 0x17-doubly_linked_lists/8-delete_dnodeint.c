#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: the head of the list
 * @index: position of the node to delete
 * Return: 1 if it succeeded or -1 if it failed
 **/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head;
	dlistint_t *node_to_delete = *head;
	unsigned int idx;
	unsigned int cont = 0;

	if (!(*head))
		return (-1);

	if (index == 0)
	{
		*head = node_to_delete->next;
		free(node_to_delete);
		if (*head)
			(*head)->prev = NULL;
		return (1);
	}

	idx = index - 1;
	while (tmp && cont != idx)
	{
		cont++;
		tmp = tmp->next;
	}

	if (cont == idx && tmp)
	{
		node_to_delete = tmp->next;
		if (node_to_delete->next)
		node_to_delete->next->prev = tmp;
		tmp->next = node_to_delete->next;
		free(node_to_delete);
		return (1);
	}

	return (-1);
}
