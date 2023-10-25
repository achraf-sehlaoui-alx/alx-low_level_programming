#include "lists.h"

/**
 * free_list - free a list
 * @head: tha head of the list to be freed
 */
void free_list(list_t *head)
{
	list_t *node;

	while (head)
	{
		haed = head->next;
		free(head->str);
		free(head);
		head = node;
	}
}
