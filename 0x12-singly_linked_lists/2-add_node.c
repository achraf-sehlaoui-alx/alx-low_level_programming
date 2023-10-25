#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - add a new node at the start of the list
 * @head: the head node of the list
 * @str: the new string of the node
 *
 * Return: the new node
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));

	if (!new || !head)
		return (NULL);

	if (str)
	{
		new->str = strdup(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
		new->len = _strlen(new->str);
	}
	new->next = *head;
	*head = new;

	return (new);
}
