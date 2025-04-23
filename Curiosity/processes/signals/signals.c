#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

int	main(int argc, char **argv)
{
	int	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		while (1)
		{
			printf("Some text\n");
			usleep(50000);
		}
	}
	else
	{
		int	time;
		kill(pid, SIGSTOP);
		while (time > 0)
		{
			printf("Insert a number of seconds to let it go: \n");
			scanf("%d", &time);
			if (time > 0)
			{
				kill(pid, SIGCONT);
				sleep(time);
				kill(pid, SIGSTOP);
			}
		}
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
