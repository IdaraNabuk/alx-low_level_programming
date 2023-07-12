#include "main.h"

/**
 * create_file - Creates a file with the given name and writes the specified
 *               text content into it.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 *         -1 if the file cannot be created or written.
 *         -1 if @filename is NULL.
 *         If @text_content is NULL, create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	if (filename == NULL)
		return (-1);

	int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file == -1)
		return (-1);

	if (text_content != NULL)
	{
		int text_len = 0;
		while (text_content[text_len])
			text_len++;

		ssize_t bytesWritten = write(file, text_content, text_len);
		if (bytesWritten == -1)
		{
			close(file);
			return (-1);
		}
	}

	close(file);
	return (1);
}
