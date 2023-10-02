#include <stdio.h>
#include <stdlib.h>

/**
 * main - Print the name of the program
 * @argc: Count arguments
 * @argv: Arguments
 * Return: Always 0 (Success)
*/

int main(int argc, char *argv[])
{
	int sum = 0;
	char *c;

	while (--argc)
	{
		for (c = argv[argc]; *c; c++)
			if (*c < '0' || *c > '9')
			{
				printf("Error\n");
				return (1);
			}
		sum += atoi(argv[argc]);
	}
	printf("%d\n", sum);
	return (0);
}
