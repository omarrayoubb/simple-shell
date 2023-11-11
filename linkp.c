#include "shell.h"

/**
*adddir - directory storage
*@head: head of list
*@dir: name of directory
*Description: store the names of directories
*Return: the address of head with new node 
*/
struct linkp *adddir(struct linkp **head, char *dir)
{
	struct linkp *new, *tmp;

	if (!dir)
	{
		return (NULL);
	}
	new = malloc(sizeof(struct linkp));
	if (!new)
	{
		return NULL;
	}

	new->d = strdup(dir);
	new->p = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->p)
		{
			tmp = tmp->p;
		}
		tmp->p = new;
	}
	return (*head);
}
/**
* linkpath - store all path var
* @envs: environment variable pass
* Description: store all via linked list
* Return : address of the first node
*/
struct linkp *linkpath(char *envs)
{
	char *token;
	struct linkp *head = NULL;
	char *cpy = strdup(envs);
	token = strtok(cpy, ":");
	while(token)
	{
		head = adddir(&head, token);
		token = strtok(NULL, ":");
	}
	free(cpy);
	return head;
}
