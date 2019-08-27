#include "holberton.h"
/**
 * cd_fun - entry current path
 * @path: store a string with current path
 */
void cd_fun(char *path)
{
	chdir(path);
}
