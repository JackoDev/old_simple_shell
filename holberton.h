#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#define CMD_SIZE 1024

extern char **environ;

/* STRUCTURE  */
typedef struct line_cmds
{
	char *cmd;
	void (*func)(char *arg);

}line_cmd;

int count_args(char **args);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
void _puts(char *str);
void args_null(char **args, int height);
int _execve(char *pathname, char *const argv[], char *const envp[]);
void cd_fun(char *path);
void pwd_fun(char *path);

#endif /** HOLBERTON_H*/
