#include "shell.h"
/**
* findexec - hello
* @args: makan
* @head: struct
* Description: l
* Return : path of variable
*/
char *findexec(char *args, struct linkp *head)
{
	struct stat st;
	char *path;
	struct linkp *tmp = head;

	while(tmp)
	{
		DIR *folder = opendir(tmp->d);
		if(!folder)
		{
			tmp = tmp->p;
			continue;
		}
		path = malloc(sizeof(char) * 2 + strlen(tmp->d) + strlen(args));
		strcpy(path, tmp->d);
		strcat(path, "/");
		strcat(path, args);
		struct dirent *rd;
		while (rd = readdir(folder) != NULL)
		{
			if (stat(path, &st) == 0)
			{
				closedir(folder);
				return (path);
			}
		}
		free(path);
		tmp = tmp->p;
	}
	return (NULL);
}
