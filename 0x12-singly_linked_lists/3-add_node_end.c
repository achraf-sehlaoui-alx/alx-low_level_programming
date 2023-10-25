#include "lists.h"

/**
 * add_node_end - add a node at the end of the list
 * @head: the head of the list
 * @str: string to put in the new node
 *
 * Return: the new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));
	list_t *t = *head;
	unsigned int size = 0;

	while (str[size])
		size++;

	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->len = size;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (t->next)
		t = t->next;
	t->next = new;
	return (new);
}
