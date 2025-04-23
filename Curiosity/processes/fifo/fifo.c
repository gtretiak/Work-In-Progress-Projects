#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	if (mkfifo("myfifo1", 0777) == -1) // 0777 is octal representation for all permissions
	{
		if (errno != EEXIST)
		{	
			printf("Error\n");
			return (1);
		}
	}
	printf("Openning\n");
	int fd = open("myfifo1", O_WRONLY);
	if (fd == -1)
		return (7);
	printf("Opened\n");
	char	c = 'B';
	if (write(fd, &c, sizeof(c)) == -1)
		return (2);
	printf("Written\n");
	close(fd);
	printf("Closed\n");
	return (0);
}
