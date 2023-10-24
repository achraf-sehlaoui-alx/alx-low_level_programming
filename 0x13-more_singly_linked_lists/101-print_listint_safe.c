#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_in_lope - Counts the number of nodes
 * in a loped listint_t list
 * @head: the head of the listint_t
 *
 * Return: the number of unique nodes in the list
 */
size_t list_in_lope(const listint_t *head)
{
	const listint_t *t, *h;
	size_t node = 1;

	if (head == NULL || head->next == NULL)
	return (0);

	t = head->next;
	h = (head->next)->next;

	while (h)
	{
		if (t == h)
		{
			t = head;
			while (t != h)
			{
				node++;
				t = t->next;
				h = h->next;
			}
			t = t->next;
			while (t != h)
			{
				node++;
				t = t->next;
			}

			return (node);
		}

	t = t->next;
	h = (h->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list (safe version)
 * @head: the head of the list
 *
 * Return: The number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t size, index = 0;

	size = list_in_lope(head);

	if (size == 0)
	{
		for (; head != NULL; size++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < size; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (size);
}
