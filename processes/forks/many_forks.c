#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

#ifndef NUM
# define NUM 4
#endif

int	main(int argc, char **argv)
{
	int	pid[NUM];

	for (int i = 0; i < NUM; i++)
	{
		pid[i] = fork();
		if (pid[i] == -1)
		{
			printf("Error while forking\n");
			return (1);
		}
		if (pid[i] == 0)
		{
			printf("\tHello from the %d process with PID %d and PPID %d\n\n\n"
				, i + 1, getpid(), getppid());
			return (0);
		}
		else
		{
			printf("Hello from the parent of the %d division with PID %d\n"
				"(parent of %d process). This parent's parent is %d\n"
				, i + 1, getpid(), pid[i], getppid());
		}
	}
	for (int i = 0; i < NUM; i++)
		wait(NULL);
	return (0);
}
