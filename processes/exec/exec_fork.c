#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	char	*arr[] = { "man", argv[1], NULL };
	char	*env[] = { "TEST", NULL };
	
	pid = fork();
	if (pid == -1)
		return (25);
	if (pid == 0)
		execve("/bin/man", arr, env);
	else
	{
		wait(NULL);
		printf("\n\nPost process after the command's execution");
	}
	return (0);
}
