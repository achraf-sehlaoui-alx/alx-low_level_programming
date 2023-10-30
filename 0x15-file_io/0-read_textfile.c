#include "main.h"

/**
 * read_textfile - read the text from a file and prints it
 * @filename: the file name to be printed
 * @letters: number of bytes to read
 *
 * Return: number of bytes printed
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file, i, size;
	char *buf = malloc(letters);

	if (!filename || !letters)
		return (0);

	file = open(filename, O_RDONLY);

	if (file == -1)
		return (0);

	i = read(file, buf, letters);
	size = write(STDOUT_FILENO, buf, i);
	close(file);
	return (size);
}
