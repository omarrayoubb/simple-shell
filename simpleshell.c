#include "shell.h"

/**
_CTD - check for errors
@length: length of string
@line: the line from user
Description: check for ending
*/
 void _CTD(ssize_t length, char *line)
{
	(void) line;
	if (length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\n");
			free(line);
			exit(0);
		}
	}
	return;
}
/**
* main - main
*
* Description: shell that execute commands
* RETURN: 0 for success 
*/
int main()
{
	char *line, **args, *envs, *fullpath;
	struct linkp* direc;
	size_t size = 0, i = 0;
	ssize_t length;

	while (length != EOF)
	{
		args = NULL;
		envs = NULL;
		if (isatty(STDIN_FILENO))
			printf("$ ");

		length = getline(&line, &size, stdin);
		if (line[length - 1] == '\n')
			(line[length - 1]) = NULL;
		_CTD(length, line);

		args = _strtok(line, " ");

		envs = getenv("PATH");
		direc = linkpath(envs);
		fullpath = findexec(args[0], direc);
		if (fullpath)
		{
			printf("%s\n", fullpath);
		}
	}
	free(direc);
	free(line);
	free(fullpath);
	return (0);
}
