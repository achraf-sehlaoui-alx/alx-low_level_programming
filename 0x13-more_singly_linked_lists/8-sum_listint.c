#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data of a list
 * @head: first node of the linked list
 *
 * Return: the sum of data
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
