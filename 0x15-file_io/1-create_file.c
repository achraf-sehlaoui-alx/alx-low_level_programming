#include "main.h"

/**
 * create_file - creates a file.
 * @filename: name of file to create
 * @text_content: text to write
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int n = 0, file;

	if (!filename)
		return (-1);

	while (text_content[n] != '\0')
		n++;

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_TRUSR | S_IWUSR);

	if (file == -1)
		return (-1);

	write(file, text_content, i);

	return (1);
}
