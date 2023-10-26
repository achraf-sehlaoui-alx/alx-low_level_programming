#include "main.h"

/**
 * print_binary - prints a number in binary
 * @n: number to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int size = sizeof(n) * 8;
	int x = 0;

	while (size)
	{
		if (n & 1L << --size)
		{
			_putchar('1');
			x++;
		}
		else if (x)
			_putchar('0');
	}
	if (!x)
		_putchar('0');
}
