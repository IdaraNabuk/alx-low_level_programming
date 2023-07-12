#include "main.h"

/**
 * read_textfile - Reads text file and prints it to the POSIX standard output.
 * @filename: Name of the file to read.
 * @letters: Number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 *         0 if the file cannot be opened or read.
 *         0 if @filename is NULL.
 *         0 if write fails or does not write the expected amount of bytes.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	FILE *file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	char *buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	ssize_t bytesRead = fread(buffer, sizeof(char), letters, file);
	if (bytesRead <= 0)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	buffer[bytesRead] = '\0'; /* Null-terminate the buffer */

	ssize_t bytesWritten = fwrite(buffer, sizeof(char), bytesRead, stdout);
	if (bytesWritten != bytesRead)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	fclose(file);
	free(buffer);
	return (bytesWritten);
}
