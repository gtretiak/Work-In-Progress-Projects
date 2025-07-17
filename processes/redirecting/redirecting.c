#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	pid;
	char	*arr[] = { "man", argv[1], NULL };
	int	err;
	int	wstatus;

	pid = fork();
	if (pid == -1)
		return (25);
	if (pid == 0)
	{
		int	file = open("output.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (50);
		dup2(file, STDOUT_FILENO); // It's going to replace stdout with the file
		close(file);
		err = execv("/bin/man", arr);
		if (err == -1)
			return (5);
	}
	else
	{ 
		wait(&wstatus); // contains the status
		if (WIFEXITED(wstatus)) // if exit status is != 0, then OK
		{
			int	code = WEXITSTATUS(wstatus);
			if (code == 0)
				printf("Success\n");
			else
				printf("Failure with status code %d\n", code);
		}
	}
	return (0);
}
