#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	
	int	id;
	int	fd[2];
	if (pipe(fd) == -1)
	{
		printf("Error while opening pipe");
		return (1);
	}
	id = fork();
	if (id == -1)
	{
		printf("fork error\n");
		return (4);
	}
	if (id == 0)
	{
		close(fd[0]);
		int	x;
		int	err;
		printf("Input the number: ");
		scanf("%d", &x);
		err = write(fd[1], &x, sizeof(int));
		if (err == -1)
		{
			printf("Error while writing\n");
			return (2);
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int	y;
	       	int	erro;
		erro = read(fd[0], &y, sizeof(int));
		if (erro == -1)
		{
			printf("Error while reading\n");
			return (3);
		}
		close(fd[0]);
		y *= 2;
		printf("Value from the child process - %d\n", y);
	}
	return (0);
}
