#include "main.h"

/**
 * flip_bits - give the number of bits to change
 * to transform one number to another
 *
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int count = 0, x;
	unsigned long int current;
	unsigned long int xor = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		current = xor >> x;
		if (current & 1)
			count++;
	}

	return (count);
}
