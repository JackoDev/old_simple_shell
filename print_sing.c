#include "holberton.h"

/**
 * print_sign - show $ symbol and path current directory
 */
void print_sign(void)
{
	char curr_path[512];

	_puts("\33[1;31m[#]cisfun@holberton\33[0m:");
	_puts("\33[1;34m");
	_puts(getcwd(curr_path, -1));
	_puts("\33[0m$ ");
}
