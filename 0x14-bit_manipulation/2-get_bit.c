#include"main.h"

/**
 * get_bit - get the value of a bit at a given index
 * @n: the number to check
 * @index: index at which to check bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(n) * 8))
		return (-1);

	return (n >> index & 1);
}
