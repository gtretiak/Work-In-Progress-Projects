#include <stdlib.h>
#include <stdio.h>

void	ft_put_den(int l, int b)
{
	int	den = 1;
	int	res = 0;
	while (den <= l)
	{
		if (l % den == 0 && b % den == 0)
			res = den; 
		den++;
	}
	printf("%d\n", res);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;
//	if (1)
	if (argc == 3)
	{
//		x = 42;
//		y = 12;
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		if (x > y)
			ft_put_den(y, x);
		else
			ft_put_den(x, y);
	}
	else
		printf("\n");
}
