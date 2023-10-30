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
	int fd = open(filename, O_RDONLY);
	ssize_t size;
	char buf[READ_BUF_SIZE * 8];

	if (!filename || !letters)
		return (0);
	
	if (fd == -1)
		return (0);

	size = read(fd, &buf[0], letters);
	size = write(STDOUT_FILENO, &buf[0], size);
	close(fd);
	return (size);
}
