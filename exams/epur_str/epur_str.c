#include <unistd.h>

void	ft_put(char *s)
{
	int	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == 32 || s[i] == 9 || s[i] == 11))
			i++;
		while (s[i] && s[i] != 32 && s[i] != 9 && s[i] != 11)
		{
			write(1, &s[i], 1);
			i++;
		}
		while (s[i] && (s[i] == 32 || s[i] == 9 || s[i] == 11))
			i++;
		if (s[i] && s[i] != 32 && s[i] != 9 && s[i] != 11)
			write(1, " ", 1);
	}
}

int	main(int argc, char **argv)
{
	char	*empty = "";
	if (argc == 2)
	{
		if (argv[1] == empty)
		{
			write(1, "\n", 1);
			return (1);
		}
		ft_put(argv[1]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
