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
	struct linkp *tmp = head;

	while (tmp)
	{
		if (args[0] == '/')
		{
			path = strdup(args);
			return (path);
		}
		path = malloc(sizeof(char) * 2 + strlen(tmp->d) + strlen(args));
		strcpy(path, tmp->d);
		strcat(path, "/");
		strcat(path, args);
		if (stat(path, &st) == 0)
		{
			return (path);
		}
		free(path);
		tmp = tmp->p;
	}
	return (NULL);
}
