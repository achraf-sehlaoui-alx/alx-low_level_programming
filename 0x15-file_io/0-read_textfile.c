#include "main.h"

/**
 * read_textfile - read the text from a file and prints it
 * @filename: the file name
 * @letters: number of bytes
 *
 * Return: number of bytes printed
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = open(filename, O_RDONLY);
	ssize_t size_bytes;
	char buf[BUF_SIZE * 8];

	if (!filename || !letters)
		return (0);
	if (fd == -1)
		return (0);

	size_bytes = read(fd, &buf[0], letters);
	size_bytes = write(STDOUT_FILEND, &buf[0], size_bytes);
	close(fd);

	return (size_bytes);
}
