#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	id, n;
	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id == 0)
		printf("Hello from the Child process with id: %d\n", id);
	else
	{
		sleep(3);
		printf("Hello from the Parent process with id: %d\n", id);
	}
	if (id != 0)
		wait(NULL);
	for (int i = n; i < n + 5; i++)
	{
		printf("%d\n", i);
		fflush(stdout); 
	}
	return (0);
}
