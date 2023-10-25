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
	unsigned int n = 0;

	while (str[n])
		n++;

	if (!new || !head)
		return (NULL);

	new->str = strdup(str);
	new->n = n;
	new->next = (*head);
	(*head) = new;

	return (*head);
}
