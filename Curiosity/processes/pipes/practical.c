#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	int	arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int	filed[2];
	int	fdesc[2];
	int	start, end;
	int	arrSize = sizeof(arr) / sizeof(int);
	if (pipe(filed) == -1 || pipe(fdesc) == -1)
		return (1);
	int 	id = fork();
	int	id2;
	if (id != 0)
		id2 = fork();
	if (id == -1 || id2 == -1)
		return (2);
	if (id == 0)
	{
		start = 0;
		end = arrSize / 3;
	}
	else if (id2 == 0)
	{
		start = arrSize / 3;
		end = start * 2;
	}
	else
	{
		start = arrSize / 3 * 2;
		end = arrSize;
	}
	int	sum = 0;
	for (int i = start; i < end; i++)
		sum += arr[i];
	printf("Calculated sum is %d\n", sum);
	int	child_1 = 0;
	int	child_2 = 0;
	if (id == 0)
	{
		close(filed[0]);
		if (write(filed[1], &sum, sizeof(int)) == -1)
			return (3);
		close(filed[1]);
	}
	else if (id2 == 0)
	{
		close(fdesc[0]);
		if (write(fdesc[1], &sum, sizeof(int)) == -1)
			return (3);
		close(fdesc[1]);
	}
	else
	{
		close(filed[1]);
		close(fdesc[1]);
		if (read(filed[0], &child_1, sizeof(int)) == -1)
			return (4);
		close(filed[0]);
		if (read(fdesc[0], &child_2, sizeof(int)) == -1)
			return (4);
		close(fdesc[0]);
	}
	int	total = sum + child_1 + child_2;
	if (id != 0 && id2 != 0)
		printf("total is %d\n", total);
	wait(NULL);
	return (0);
}
