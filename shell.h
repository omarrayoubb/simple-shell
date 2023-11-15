#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <malloc.h>
extern char **environ;
/**
* struct linkp - linkpath
* @d: name of folder
* @p: pointer to the next folder
* Description: link path variables in a linked list
*/
typedef struct linkp
{
	char *d;
	struct linkp *p;
} linkp;

void _CTD(ssize_t length, char *buff);
char **_strtok(char *token, const char *delim);
struct linkp *adddir(struct linkp **head, char *dir);
struct linkp *linkpath(char *envs);
char *findexec(char *args, struct linkp *head);
struct linkp *free_list(struct linkp *path);
void exec(char **args);
void *_realloc(void *ptr, size_t size);
void freeArgs(char **args);
struct linkp *freepath(struct linkp *path);
int _putchar(char c);
size_t _strlen(const char *args);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
char *_strcpy(char *path, const char *src);
#endif
