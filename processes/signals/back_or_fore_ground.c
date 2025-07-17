#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

int	main(int argc, char **argv)
{
	int	x;
	printf("Insert a number: \n");
	scanf("%d", &x);
	printf("res: %d * 5 = %d\n", x, x * 5);
	return (0);
}
