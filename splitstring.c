#include "shell.h"
/**
_strtok - split strings
@token: string
@delim: delemiter that splith the string
Description: split the command into pieces
Return: pointer
*/
char **_strtok(char *tok, const char *delim)
{
	char **args;
	char *token;
	char *copy = malloc(strlen(tok) + 1 * sizeof(char));
	int i = 0, j = 0;
	token = strtok(tok, delim);
	copy = token;
	while (copy)
	{
		j++;
		copy = strtok(NULL, delim);
	}
	args = malloc(sizeof(char *) * j + 1);
	while (token)
	{
		args[i++] = token;
		token = strtok(NULL, delim);
	}
	return (args);
}
