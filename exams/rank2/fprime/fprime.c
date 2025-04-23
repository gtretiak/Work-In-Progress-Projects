#include <stdio.h>
#include <stdlib.h>

void	ft_print(int n)
{
	if (n < 10)
		printf("%d", n);
	else
	{
		ft_print(n / 10);
		ft_print(n % 10);
	}
}

void	ft_prime(int n)
{
	int	factor = 1;
	if (n == 1)
	{
		printf("1");
		return ;
	}
	while (n >= factor)
	{
		++factor;
		while (n % factor == 0)
		{
			ft_print(factor);
			if (n > factor)
				printf("*");
			n /= factor;
		}
//		if (n < factor)
//			return ;
	}	
}

int	main(int ac, char **av)
{
	int	n;

	if (ac != 2)
		printf("\n");
	else
	{
		n = atoi(av[1]);
		if (n < 0)
			printf("\n");
		else
		{
			ft_prime(n);
			printf("\n");
		}
	}
}
