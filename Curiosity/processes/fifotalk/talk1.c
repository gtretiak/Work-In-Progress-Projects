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
	srand(time(NULL));
	int	i = 0;
	int	sum = 0;
	for (int i = 0; i < 5; i++)
	{
		arr[i] = rand() % 1000;
		printf("Generated %d\n", arr[i]);
	}
	printf("Openning...\n");
	int fd = open("sum", O_WRONLY);
	if (fd == -1)
		return (1);
	printf("Opened with success. Writing...\n");
	//Next we can write the whole array or whatever indexes by using a loop
	if (write(fd, arr, sizeof(int) * (sizeof(arr) / sizeof(int))) == -1)
		return (2);
	printf("All numbers are written\nClosing...\n");
	close(fd);
	printf("Closed with success\n\n");
	// Now let's make these programs communicate both directions:
	printf("Receiving the sum from another program...\nOpenning...\n");
	fd = open("sum", O_RDONLY);
	if (fd == -1)
		return (3);
	printf("Opened\nReading...\n");
	if (read(fd, &sum, 4) == -1)
		return (4);
	printf("Sum is %d\nClosing...\n", sum);
	close(fd);
	printf("Closed\n");
	return (0);
}
