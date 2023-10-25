#include <stdio.h>

void prt_constructor(void) __attribute__ ((constructor));

/**
 * prt_constructor - prints a sentence before the main()
 */
void prt_constructor(void)
{
	printf("You're beat! and yet, you must allow,\n"
		"I bore my house upon my back!\n");
}
