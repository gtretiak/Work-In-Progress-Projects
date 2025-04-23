#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	fd[3][2]; // P -> C // C -> C // C-> P
	int	i;
	for (i = 0; i < 3; i++)
	{
		if (pipe(fd[i]) == -1)
			return (1);
	}
	int	pid1 = fork();
	if (pid1 == -1)
		return (2);
	if (pid1 == 0) // Child
	{
		int	x;
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);
		if (read(fd[0][0], &x, 4) == -1)
			return (3);
		printf("Received %d\n", x);
		x += 5;
		close(fd[0][0]);
		if (write(fd[1][1], &x, 4) == -1)
			return (4);
		printf("Written %d\n", x);
		close(fd[1][1]);
		return (0);
	}
	int pid2 = fork();
	if (pid2 == -1)
		return (7);
	if (pid2 == 0)
	{
		int	x;

		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		close(fd[2][0]);
		if (read(fd[1][0], &x, 4) == -1)
			return (8);
		printf("Received %d\n", x);
		x *= 2;
		close(fd[1][0]);
		if (write(fd[2][1], &x, 4) == -1)
			return (9);
		printf("Written %d\n", x);
		close(fd[2][1]);
		return (0);
	}
	close(fd[0][0]);
	close(fd[1][1]);
	close(fd[1][0]);
	close(fd[2][1]);
	srand(time(NULL));
	int	x = rand() % 10;
	if (write(fd[0][1], &x, 4) == -1)
		return (5);
	close(fd[0][1]);
	printf("Written %d\n", x);
	if (read(fd[2][0], &x, 4) == -1)
		return (6);
	printf("Result is %d\n", x);
	close(fd[2][0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
