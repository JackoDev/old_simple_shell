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

int count_args(char **args);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
void print(const char str[], int len);
#endif /** HOLBERTON_H*/
