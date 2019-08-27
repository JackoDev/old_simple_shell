#include "holberton.h"
/**
 * search_cmd - entry
 * @args: command
 * Return: command with path
 */
char *search_cmd(char *args)
{
	char path[128] = "/bin/";
	int cmd;	/* */

	DIR *dir;
	struct dirent *curr_dir;

	dir = opendir("/bin")
	if (dir == NULL)
	{
		perror("Error: ");
		exit(-1);
	}

	while ((curr_dir = readdir(dir)) != NULL)
	{
		cmd = strcmp(curr_dir->d_name, args);
		if (cmd == 0)
		{
			closedir(dir);
			return (_strcat(path, args));
		}
	}
	closedir(dir);
	return (args);
}
