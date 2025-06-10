#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == 32 || s[i] == 9 || s[i] == 11)) 
			i++;
		while (s[i] && !(s[i] == 32 || s[i] == 9 || s[i] == 11)) 
		{
			write(1, &s[i], 1);
			i++;
		}
		while (s[i] && (s[i] == 32 || s[i] == 9 || s[i] == 11)) 
			i++;
		if (s[i])
			write(1, "   ", 3);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
		write(1, "\n", 1);
	else
	{
		ft_putstr(av[1]);
		write(1, "\n", 1);
	}	
}
