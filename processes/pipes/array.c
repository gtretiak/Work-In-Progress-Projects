#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	fd[2];
	if (pipe(fd) == -1)
		return (2);
	int	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		close(fd[0]);
		int	size; // This is a crucial param to send
		int	i;
		int	arr[10];
		srand(time(NULL));
		size = rand() % 10 + 1; // Because it's random
		printf("Generated numbers are: ");
		for (i = 0; i < size; i++)
		{
			arr[i] = rand() % 11;
			printf("%d", arr[i]);
			if (i + 1 == size)
				printf("\n");
			else
				printf(", ");
		}
		if (write(fd[1], &size, sizeof(int)) == -1) // So we send it first
			return (4);
		printf("Size %d is sent to the parent\n", size);
		if (write(fd[1], arr, sizeof(int) * size) == -1)
			return (3);
		printf("An array has sent\n");
		close(fd[1]);
	}
	else
	{
		int	arr[10];
		int	size, i, sum = 0;
		close(fd[1]);
		if (read(fd[0], &size, sizeof(int)) == -1) // Once we've read it..,
			return (5);
		printf("An array's size %d has received\n", size);
		if (read(fd[0], arr, (sizeof(int) * size)) == -1) // .., we know how to read an array
			return (6);
		printf("An array has received\n");
		close(fd[0]);
		for (i = 0; i < size; i++)
			sum += arr[i];
		sleep(1);
		printf("The sum is %d\n", sum);
		wait(NULL);
	}
	return (0);
}
