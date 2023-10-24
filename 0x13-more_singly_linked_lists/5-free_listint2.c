#include "lists.h"

/**
 * free_listint2 - free a linked list
 * @head: pointer to the first node of the list to be free
 */
void free_listint2(listint_t **head)
{
	listint_t *node;

	if (!head)
		return;

	while (*head)
	{
	node = (*head)->next;
	free(*head);
	*head = node;
	}

	*head = NULL;
}
