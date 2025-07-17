#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

int	main(int argc, char **argv)
{
	int	arr[5];
	int	sum = 0;
	int	i = 0;
	int	fd = 0;

	printf("Openning...\n");
	fd = open("sum", O_RDONLY);
	if (fd == -1)
		return (5);
	printf("Opened with success\nReading...\n");
	//We can read the whole array or whatever indexes by using a loop
	if (read(fd, arr, sizeof(int) * (sizeof(arr) / sizeof(int))) == -1)
		return (6);
	while (i < 5)
		sum += arr[i++];
	printf("All %d numbers are received\nSum is calculated\nClosing...\n", i);
	close(fd);
	// Now we are going to make these programs communicate in opposite direction:
	printf("Giving the sum back. Openning...\n");
	fd = open("sum", O_WRONLY);
	if (fd == -1)
		return (7);
	printf("Opened with success\nWriting...\n");
	if (write(fd, &sum, 4) == -1)
		return (8);
	printf("Closing...\n");
	close(fd);
	printf("Closed\n");
	return (0);
}
