#include <unistd.h>

void	ft_meat(char *str)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (str[i + 1] == 32 || (str[i + 1] >= 9 && str[i + 1] <= 13))
				str[i] -= 32;
			else if (str[i + 1] == '\0')
				str[i] -= 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	args;
	if (argc > 1)
	{
		i = 1;
		args = argc - 1;
		while (args)
		{
			ft_meat(argv[i]);
			write(1, "\n", 1);
			i++;
			args--;
		}
	}
	else
		write(1, "\n", 1);
}
