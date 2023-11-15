#include "shell.h"
/**
* exec - execute
* @args: the string that is have the path and arguments
* Description: execute the program
*/
void exec(char **args)
{
	int st;
	pid_t id;

	if (!args || !args[0])
		return;
	id = fork();
	if (id == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(getenv("_"));
			exit(EXIT_FAILURE);
		}
	}
	else if (id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&st);
	}
}
