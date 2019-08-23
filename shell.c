#include "holberton.h"

int main(int ac, char *arv[])
{
/* Create Proccess*/
	(void)ac ;
/* symbol */

	pid_t pid;
/* getline */
	int gl, i;
	char *buf = NULL;

	int cmp = 0;
	char *line_cmd = NULL;
	size_t size = 1024;
	int len_cmd = 1024;
/* strtok */
	char *cmd;
	const char s[2] = " ";
	char *argv[size];

	struct stat filestat;
	int bin_stat;

	int status;
/* allocate for clean command of \n */
	line_cmd = (char *) malloc(len_cmd * sizeof(char));
	if (line_cmd == NULL)
		return (-1);

	while (1)
	{
		_puts("#cisfun$ ");
		
		gl = getline(&buf, &size, stdin); 
		if(gl == -1)
		{
			exit(-1);
		}
		if (*buf == EOF)
		{
			kill(pid, SIGKILL);
			exit(0);		
		}
		if (_strcmp(buf, "\n") != 0)
		{
			_strcpy(line_cmd, buf);
			cmd = strtok(line_cmd, s);
		}
		else
		{
			cmd = strtok(buf, s);
		}			
			
		for(i = 0; cmd != NULL; i++)
		{	
			argv[i] = cmd;
			cmd = strtok(NULL, s);
		} 

		if ((_strcmp(argv[0],"exit")) == 0)
		{
			kill(pid, SIGKILL);
			exit(0);
		}
		pid = fork();
		if(pid == 0)
		{
			
			bin_stat = lstat(argv[0], &filestat);
			if (bin_stat < 0 && _strcmp(argv[0],"\n") != 0 )
				perror(arv[0]);
			else
			{	
				execve(argv[0], argv, NULL);
			}
		}
		else
		{				
			wait(&status);
			kill(pid, SIGKILL);
		}
	}
	return (0);
}
