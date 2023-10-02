#include <unistd.h>
#include "main.h"

/**
 * _putchar - wrtes the character c to stdout
 * @c: the character to print
 * Return: 1 (success) or -1 (error/error is set appropriately)
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
