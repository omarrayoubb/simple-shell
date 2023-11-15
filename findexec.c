#include "shell.h"
/**
* findexec - hello
* @args: makan
* @head: struct
* Description: lsdfasdff
* Return: path of variable
*/
char *findexec(char *args, struct linkp *head)
{
	struct stat st;
	char *path;
	char *dent;
	struct linkp *tmp = head;

	while (tmp)
	{
		size_t i = 0;

		dent = _strdup(tmp->d);
		if (args[0] == '/')
		{
			path = _strdup(args);
			return (path);
		}
		path = malloc(sizeof(char) * 2 + _strlen(tmp->d) + _strlen(args));
		for (i = 0; i < _strlen(tmp->d); i++)
		{
			path[i] = dent[i];
		}
		path[i] = '\0';
		_strcat(path, "/");
		_strcat(path, args);
		if (stat(path, &st) == 0)
		{
			return (path);
		}
		free(path);
		tmp = tmp->p;
	}
	return (NULL);
}
