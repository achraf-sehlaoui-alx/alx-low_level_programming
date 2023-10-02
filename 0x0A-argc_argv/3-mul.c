#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 (Success), 1 (Error)
*/

int main(int argc, char *argv[])
{
	int prd;

	if (argc == 3)
	{
		prd = atoi(argv[1]) * atoi(argv[2]);
		printf("%d\n", prd);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
