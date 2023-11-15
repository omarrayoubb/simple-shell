#include "shell.h"
/**
* _strtok - strtok for string
* @tok: first string
* @delim: second string
* Description: strtok the string into string in 2d array
* Return: address of new string
*/
char **_strtok(char *tok, const char *delim)
{
	char **args = NULL;
	char *token;
	int i = 0;

	token = strtok(tok, delim);
	while (token)
	{
		args = _realloc(args, (i + 1) * sizeof(char *));
		if (!args)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}

		args[i] = strdup(token);
		if (!args[i])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, delim);
		i++;
	}

	args = _realloc(args, (i + 1) * sizeof(char *));
	if (!args)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	args[i] = NULL;

	return (args);
}
/**
* _realloc - prt
* @ptr: pointer
* @size: size
* Description: reseize the array
* Return: return the pointer
*/

void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t i;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (malloc(size));
	}

	new_ptr = malloc(size);

	if (new_ptr != NULL)
	{

	size_t old_size = malloc_usable_size(ptr);
	size_t copy_size = (size < old_size) ? size : old_size;
	char *old_ptr = (char *)ptr;
	char *new_ptr_char = (char *)new_ptr;

	for (i = 0; i < copy_size; i++)
	{
		new_ptr_char[i] = old_ptr[i];
	}

	free(ptr);
	}

	return (new_ptr);
}
/**
* freeArgs - freee
* @args: freeeeeeeeeeeee
* Description: free all strings
*/
void freeArgs(char **args)
{
	size_t i = 0;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}
