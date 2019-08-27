#include "holberton.h"

int main()
{
/* PATH */
	pid_t pid;
/* getline,iterator,execve and wait */
	int gl, i, count = 0, _exec, status; 
	char *buf = NULL, *line_cmd = NULL; /* buffer and command line */
	size_t size = 1024;
/* strtok */
	char *cmd, *argv[CMD_SIZE];
	const char s[2] = " "; 
/* ALLOCATE*/
/* allocate for clean command of \n */
	line_cmd = (char *) malloc(CMD_SIZE * sizeof(char));
	if (line_cmd == NULL)
		exit(-1);

	while (1)
	{
		print_sign();

		gl = getline(&buf, &size, stdin);

		if(gl == -1)
			exit(-1);

		if (*buf == EOF)
		{
			free(line_cmd);
			free(buf);
			kill(pid, SIGQUIT);
			exit(0);		
		}

		if (_strcmp(buf, "\n") != 0)
		{
			_strcpy(line_cmd, buf);
			cmd = strtok(line_cmd, s);
		}
		else
			cmd = strtok(buf, s);
		
		for(i = 0; cmd != NULL; i++)
		{	
			argv[i] = cmd;
			cmd = strtok(NULL, s);
		} 
		count = i;
		if ((_strcmp(argv[0],"exit")) == 0)
		{
			free(line_cmd);
			free(buf);
			kill(pid, SIGQUIT);
			exit(0);
		}
		pid = fork();
		if(pid == 0)
		{
			_exec = _execve(search_cmd(argv[0]), argv, environ);
			if (_exec == -1)
				perror(argv[0]);
		}
		else
		{				
			wait(&status);
			kill(pid, SIGQUIT);
		}	
		args_null(argv, count);
	}
	return (0);
}
