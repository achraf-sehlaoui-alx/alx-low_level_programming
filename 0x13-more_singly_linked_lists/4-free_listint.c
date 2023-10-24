#include "lists.h"

/**
 * free_listint - free a linked list
 * @head: pointer to the first node
 */
void free_listint(listint_t *head)
{
	listint_t *node;

	while (head)
	{
		node = head->next;
		free(head);
		head = node;
	}
}
