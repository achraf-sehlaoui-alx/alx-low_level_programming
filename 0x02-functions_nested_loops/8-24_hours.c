#include "main.h"

/**
 * jack_bauer - prints every minute of the day of Jack Bauer
 * starting from 00:00 to 23:59
*/

void jack_bauer(void)
{
	int min, hr;

	hr = 0;

	while (hr < 24)
	{
		min = 0;
		while (min < 60)
		{
			_putchar((hr / 10) + 48);
			_putchar((hr % 10) + 48);
			_putchar(':');
			_putchar((min / 10) + 48);
			_putchar((min % 10) + 48);
			_putchar('\n');
			min++;
		}
		hr++;
	}
}
