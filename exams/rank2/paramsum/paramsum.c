#include <unistd.h>

void	ft_put(int x)
{
	char	c;
	if (x < 10)
	{
		c = x + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_put(x / 10);
		ft_put(x % 10);
	}
}

int	main(int ac, char **av)
{
	int	x;
	char	*s;
       	s = av[1];
	if (ac == 1)
		write(1, "0\n", 2);
	else
	{
		x = ac - 1;
		ft_put(x);
		write(1, "\n", 1);
	}
}
