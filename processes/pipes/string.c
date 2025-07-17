#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <string.h>

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
		char	str[200];
		int	size;

		printf("Input a string: ");
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = '\0';
		size = strlen(str);
		printf("size (strlen(str) is %d\n", size);
		if (write(fd[1], &size, sizeof(int)) == -1)
			return (3);
		printf("A string's size %d has been sent\n", size);
		if (write(fd[1], str, size + 1) == -1)
			return (4);
		printf("A string has been written and therefore sent\n");
		close(fd[1]);
	}
	else
	{
		char	str[200];
		int	size;
		close(fd[1]);
		if (read(fd[0], &size, sizeof(int)) == -1) // Once we've read it..,
			return (5);
		printf("A string's size %d has been received\n", size);
		if (read(fd[0], str, size + 1) == -1) // .., we know how to read an array
			return (6);
		printf("A string has been received\n");
		close(fd[0]);
		sleep(1);
		printf("The string is \"%s\"\n", str);
		wait(NULL);
	}
	return (0);
}
