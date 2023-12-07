#include "lists.h"

/**
 * sum_dlistint - sum of all the data of a dlistint_t list
 * @head: the head of the list
 * Return: sum or 0 if the list is empty
 **/
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
