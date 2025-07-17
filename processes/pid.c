#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	id, res;
	id = fork();
//This is a right way to execute a child process first
//
//	if (id != 0) // But this line is kind of redundant. Wait is gonna check if there is a child
		res = wait(NULL);
	if (res == -1) //error if there is no kids
		printf("No kids anymore\n");
	else
		printf("return value by wait is %d (child's ID)\n", res);
//
//Here is where child becomes abandoned (due to parent's terminating)
//The child is orphaned, but then adapted by init (the 1st PID)
//Init automatically calls wait
//	if (id == 0)
//		sleep(5);
//
// Since the parent doesn't wait for its child with wait or waitpid
// But it's still running, whereas the child is terminated
// It leads to appearance of zombie process (child)
// That zombie lives during sleeping time until parent dies
/*
	if (id == 0)
		exit(0);
	else
		sleep(10);
*/
	printf("Current PID is %d\nParent PID is %d\n"
		"Its child ID is %d\n\n\n", getpid(), getppid(), id);
	return (0);
}
