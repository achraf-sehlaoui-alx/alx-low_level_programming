#include "main.h"

/**
 * clear_bit - clear the bit to 0 at index
 * @n: the nmbr to index
 * @index: index
 * Return: 1 if success, -1 on error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
