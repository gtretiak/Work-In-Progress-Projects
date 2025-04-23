#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	pid1, pid2;
	pid1 = fork();
	if (pid1 == -1)
		return (1);
	if (pid1 == 0)
	{
		sleep(2);
		printf("Finished %d\n", getpid());
		return (0);
	}
	pid2 = fork();
	if (pid2 == -1)
		return (2);
	if (pid2 == 0)
	{
		sleep(1);
		printf("Finished %d\n", getpid());
		return (0);
	}
	int	pid1res = waitpid(pid1, NULL, 0);
	printf("Waited for %d\n", pid1res);
	int	pid2res = waitpid(pid2, NULL, 0);
	printf("Waited for %d\n", pid2res);
	//
/*	int	pid1res = wait(NULL);
	printf("Waited for %d\n", pid1res);
	int	pid2res = wait(NULL);
	printf("Waited for %d\n", pid2res);*/
	return (0);
}
