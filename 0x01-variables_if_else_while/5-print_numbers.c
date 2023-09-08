#include <stdio.h>

/**
 * main - print numbers > 0 to 9
 *
 * Description: a program that prints all single digit numbers of base 10
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%d", i);
	}
	putchar('\n');
	return (0);
}

