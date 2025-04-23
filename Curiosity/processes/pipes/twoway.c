#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	p1[2]; // C -> P
	int	p2[2]; // P -> C
		       // p[0] is for reading, whereas p[1] is for writing
	if (pipe(p1) == -1 || pipe(p2) == -1)
		return (1);
	int	pid = fork();
	int	x;
	if (pid == -1)
		return (2);
	if (pid == 0) // Child
	{
		close(p1[0]); // we can close it immediatly because we don't need to read from THIS pipe
		close(p2[1]); // because we don't need to write to it (it's parent's privilage)
		if (read(p2[0], &x, 4) == -1)
			return (3);
		printf("Received %d\n", x);
		x *= 4;
		if (write(p1[1], &x, 4) == -1)
			return (4);
		printf("Written %d\n", x);
		close(p1[1]); // we are done with writing, so let's close it
		close(p2[0]); // we are also done with reading, so let's close it too
	}
	else // Parent
	{
		close(p2[0]); // This is read-end for P -> C communication, so we don't need it
		close(p1[1]); // This write-end is for a child process
		srand(time(NULL));
 		int	y = rand() % 10;
		if (write(p2[1], &y, 4) == -1)
			return (5);
		printf("Written %d\n", y); // if pipe is just one, removing this line gets us to trouble
		if (read(p1[0], &y, 4) == -1)
			return (6);
		printf("Result is %d\n", y);
		close(p1[0]); 
		close(p2[1]);
	}
	return (0);
}
