#include "main.h"

/**
 * get_endianness - get the endianness of the sys
 *
 * Return: 0 if big endian, 1 if small endian
 */
int get_endianness(void)
{
	int n;
	char *x;

	n = 1;
	x = (char *)&n;
	return (*x);
}
