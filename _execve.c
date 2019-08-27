#include "holberton.h"

int _execve(char *pathname, char *const argv[], char *const envp[])
{
	int i, cmp, n_exec;

	line_cmd cmds[] = {
			{"cd", cd_fun},
			{"pwd", pwd_fun},
			{NULL, NULL}
	};
	if (_strcmp(pathname, "\n") == 0)
		return (0);
	n_exec = execve(pathname, argv, envp);
	if (n_exec < 0)
	{
		if (pathname != NULL)
		{
			for (i = 0; cmds[i].cmd != NULL; i++)
			{
				cmp = _strcmp(pathname,cmds[i].cmd);
				if (cmp == 0)
				{	
					cmds[i].func(argv[1]);
					return(0);
				}				
			}
		}
	}	
	return (n_exec);
}
void cd_fun(char *path)
{
	chdir(path);
}
void pwd_fun(char *path)
{
	(void) *path;
	char buffer[512];

	_puts(getcwd(buffer, -1));
	_putchar('\n');
}
