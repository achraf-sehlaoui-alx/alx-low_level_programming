#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to the first node
 *
 * Return: the data of the node that was deleted
 */
int pop_listint(listint_t **head)
{
	listint_t *t;
	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	t = (*head)->next;
	free(*head);
	*head = t;

	return (num);
}
