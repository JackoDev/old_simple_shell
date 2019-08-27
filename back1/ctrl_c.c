void ctrl_c(int x)
{
	(void) x;
	write(1, "\n$ ", 3);
	fflush(stdout);
}
