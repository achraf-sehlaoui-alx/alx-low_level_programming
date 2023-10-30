#include "main.h"

/**
 * append_text_to_file - appends text at file
 * @filename: name of the file to create
 * @text_content: content to write
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int i = 0, file;

	if (!filename)
		return (-1);

	if (!text_cont)
		text_cont = "";

	while (text_content[i] != '\0')
	{
		i++;
	}

	file = open(filename, O_WRONLY | O_APPEND);

	if (file == -1)
		return (-1);

	write(file, text_content, i);

	return (1);
}
