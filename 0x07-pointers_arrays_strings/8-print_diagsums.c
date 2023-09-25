#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Entry point
 * @a: input
 * @size: input
 * Return: Always 0 (Success)
*/

void print_diagsums(int *a, int size)
{
	int sum01, sum02, y;

	sum01 = 0;
	sum02 = 0;

	for (y = 0; y < size; y++)
	{
		sum01 = sum01 + a[y * size + y];
	}

	for (y = size - 1; y >= 0; y--)
	{
		sum02 += a[y * size + (size - y - 1)];
	}

	printf("%d, %d\n", sum01, sum02);
}
