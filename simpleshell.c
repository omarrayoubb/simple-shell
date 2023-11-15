#include "shell.h"
/**
* _CTD - check for errors
* @length: length of string
* @line: the line from user
* Description: check for ending
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

}
/**
* main - main
*
* Description: shell that execute commands
* Return: 0 for success
*/
int main(void)
{
	char *line = '\0', **args, *envs, *fullpath;
	struct linkp *direc;
	size_t size = 0;
	ssize_t length;

	while (length != EOF)
	{
		args = NULL;
		envs = NULL;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		length = getline(&line, &size, stdin);
		if (line[0] == '\n')
			continue;
		if (line[length - 1] == '\n')
			(line[length - 1]) = '\0';
		_CTD(length, line);
		args = _strtok(line, " ");

		envs = getenv("PATH");
		direc = linkpath(envs);
		fullpath = findexec(args[0], direc);
		if (!fullpath)
		{
			perror("hsh");
		}
		if (fullpath)
		{
			free(args[0]);
			args[0] = fullpath;
			exec(args);
		}
		freeArgs(args);
		freepath(direc);
	}
	free(line);
	free(fullpath);
	return (0);
}
