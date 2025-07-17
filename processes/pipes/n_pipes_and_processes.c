#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

#ifndef NUM
# define NUM 4
#endif

int	main(int argc, char **argv)
{
	int	fd[NUM][2]; // P -> C // C -> C // C-> P
	int	pids[NUM - 1];
	for (int i = 0; i < NUM; i++)
	{
		if (pipe(fd[i]) == -1)
			return (1);
	}
	for (int i = 0; i < NUM - 1; i++)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			return (2);
		if (pids[i] == 0)
		{
			for (int j = 0; j < NUM - 1; j++)
			{
				if (i != j)
					close(fd[j][0]);
				if (i + 1 != j)
					close(fd[j][1]);
			}
			int	x;
			if (read(fd[i][0], &x, 4) == -1)
			{
				printf("Error reading fd[%d][0]\n", i);
				return (3);
			}
			printf("The %d child process has received %d; ", i + 1, x);
			x -= 1;
			close(fd[i][0]);
			if (write(fd[i + 1][1], &x, 4) == -1)
			{
				printf("Error writing fd[%d][1]\n", i + 1);
				return (4);
			}
			printf("written %d\n", x);
			close(fd[i + 1][1]);
			return (0);
		}
	}
	close(fd[0][0]);
	close(fd[NUM - 1][1]);
	for (int i = 0; i < NUM; i++)
	{
		if (i != 0)
			close(fd[i][1]);
		if (i != NUM - 1)
			close(fd[i][0]);
	}
	srand(time(NULL));
	int	x = rand() % 10;
	if (write(fd[0][1], &x, 4) == -1)
		return (5);
	close(fd[0][1]);
	printf("Written random num from main: %d\n", x);
	if (read(fd[NUM - 1][0], &x, 4) == -1)
		return (6);
	printf("The final result received by main is %d\n", x);
	for (int i = 0; i < NUM - 1; i++)
		wait(NULL);
	close(fd[NUM - 1][0]);
	return (0);
}
