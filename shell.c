#include "holberton.h"

int main(int ac, char *arv[])
{
/* Create Proccess*/
	(void)ac ;
/* PATH */
/*
char *PATH= "/bin/";
	char *pathname = NULL;
*/	
	pid_t pid;
/* getline */
	int gl, i, count = 0;
	char *buf = NULL;
	char *line_cmd = NULL;
	size_t size = 1024;
/* strtok */
	char *cmd;
	const char s[2] = " ";
	char *argv[CMD_SIZE];

	struct stat filestat;
	int bin_stat;

	int status;
/* allocate for clean command of \n */
	line_cmd = (char *) malloc(CMD_SIZE * sizeof(char));
	if (line_cmd == NULL)
		return (-1);

	while (1)
	{
		_puts("#cisfun$ ");

		gl = getline(&buf, &size, stdin);

		if(gl == -1)
			exit(-1);

		if (*buf == EOF)
		{
			free(line_cmd);
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
			kill(pid, SIGQUIT);
			exit(0);
		}
		pid = fork();
		if(pid == 0)
		{
			
			bin_stat = lstat(argv[0], &filestat);
			if (bin_stat < 0 && _strcmp(argv[0],"\n") != 0 )
			{
				perror(arv[0]);
				kill(pid, SIGCONT);
			}
			else
			{	
				execve(argv[0], argv, environ);
			}
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

