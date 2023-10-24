#include "lists.h"

/**
 * reverse_listint - reverses a list
 * @head: pointer to the first node
 *
 * Return: the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_node = NULL;
	listint_t *next_node = NULL;

	if (!head || !*head)
		return (NULL);

	while (*head)
	{
		next_node = (*head)->next;
		(*head)->next = prev_node;
		prev_node = *head;
		*head = next_node;
	}

	*head = prev_node;

	return (*head);
}
