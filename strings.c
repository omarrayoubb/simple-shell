#include "shell.h"
/**
* _strlen - string length
* @args: args
* Description: args to be measured
* Return: number of characters
*/
size_t _strlen(const char *args)
{
	size_t i = 0;

	while (args[i])
	{
		i++;
	}
	return (i);
}
/**
* _strcat - cat
* @path: hello
* @tmp: hello
* Description: hellllllo
* Return: new string
*/
char *_strcat(char *path, const char *tmp)
{
	size_t length = _strlen(path);
	size_t i;

	for (i = 0; tmp[i] != '\0'; i++)
	{
		path[length + i] = tmp[i];
	}

	path[length + i] = '\0';
	return (path);
}
/**
* _strdup - cat
* @str: hello
* Description: helllllloadf
* Return: new string
*/
char *_strdup(const char *str)
{
	size_t len = _strlen(str), i = 0;
	char *new_str = malloc((len + 1) * sizeof(char));

	if (!new_str)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i <= len; i++)
	{
		new_str[i] = str[i];
	}

	return (new_str);
}
