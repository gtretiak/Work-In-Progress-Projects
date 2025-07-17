#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

void	ft_handle_sigusr1(int sig)
{
	char	*msg = "\nHint: remember that multiplication is repetitive addition\n";
	write(1, msg, 59);
}

int	main(int argc, char **argv)
{
	int	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		sleep(4);
		kill(getppid(), SIGUSR1);
		exit(0);
	}
	else
	{
		int	x;
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &ft_handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);
		printf("What is the res 3 * 5?\n");
		scanf("%d", &x);
		kill(pid, SIGINT);
		wait(NULL);
		if (x == 15)
		{
			printf("Correct!\n");
		}
		else
		{
			printf("Not really...\n");
		}
	}
	return (0);
}
