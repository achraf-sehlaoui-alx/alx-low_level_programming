#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: 0
*/

char *_strdup(char *str)
{
	char *cop;
	int i = 0, r = 0;

	if (str == NULL)
		return (NULL);

	while (str[i] != '\0')
		i++;

	cop = malloc(sizeof(char) * (i + 1));

	if (cop == NULL)
		return (NULL);

	for (r = 0; r < i; r++)
		cop[r] = str[r];

	return (cop);
}
