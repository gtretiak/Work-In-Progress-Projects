#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	if (argc == 4)
	{
		x = atoi(argv[1]);
		y = atoi(argv[3]);
		if (argv[2][0] == '*')
			printf("%d\n", x * y);
		else if (argv[2][0] == '/')
			printf("%d\n", x / y);
		else if (argv[2][0] == '+')
			printf("%d\n", x + y);
		else if (argv[2][0] == '-')
			printf("%d\n", x - y);
		else if (argv[2][0] == '%')
			printf("%d\n", x % y);
	}
	else
		write(1, "\n", 1);
}
