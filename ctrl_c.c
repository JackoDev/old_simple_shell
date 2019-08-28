#include "holberton.h"
/**
 * ctrl_c - function to handle ctrl+c
 * @x: parameter to operate
 * Return: its a void function
 */
void ctrl_c(int x)
{
	(void) x;
	write(1, "\n$ ", 3);
	_puts("\n");
	/*print_sign();*/
	fflush(stdout);
}
