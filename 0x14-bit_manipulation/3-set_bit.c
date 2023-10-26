#include "main.h"

/**
 * set_bit - sets the value of a bit at index
 * @n: number to index
 * @index: index to set the bit
 *
 * Return: 1 if success, -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit;

	if (index >= (sizeof(n) * 8))
		return (-1);
	bit = 1 << index;
	*n = *n | bit;
	return (1);
}
