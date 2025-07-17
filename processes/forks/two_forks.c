#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	int	id1, id2, res;
	id1 = fork();
	id2 = fork();
	res = 2;
	while (wait(NULL) != -1 && errno != ECHILD)
	{
		if (id1 != 0 && id2 != 0)
		{
			printf("The %dnd process of PID %d is finished\n\n", 
				res, getpid());
			res--;
		}
		else
			printf("The child of PID %d with PPID %d, "
				"id1 %d and id2 %d (grandchild) is finished\n\n", 
				getpid(), getppid(), id1, id2);
	}
	if (id1 == 0)
	{
		if (id2 == 0)
			printf("we are in the process Z"
				" (Grandchild) with id1 %d and id2 %d\n"
				"PID %d and PPID %d\n\n", id1, id2, getpid(), getppid());
		else
			printf("we are in the process X"
				" (1nd child) with id1 %d and id2 %d\n"
				"PID %d and PPID %d\n\n", id1, id2, getpid(), getppid());
	}
	else
	{
		if (id2 == 0)
			printf("we are in the process Y"
				" (2st child) with id1 %d and id2 %d\n"
				"PID %d and PPID %d\n\n", id1, id2, getpid(), getppid());
		else
			printf("we are in the main process"
				" (Grandfather) with id1 %d and id2 %d\n"
				"PID %d and PPID %d\n\n", id1, id2, getpid(), getppid());
	}
	return (0);
}
