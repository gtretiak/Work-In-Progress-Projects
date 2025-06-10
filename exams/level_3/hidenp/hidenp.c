#include <unistd.h>

char	*ft_check(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;
	while (s1[i])
	{
		while (s2[j] && s2[j] != s1[i])
			j++;
		if (!s2[j])
			return ("0");
		j++;
		i++;
	}
	return ("1");
}

int	main(int argc, char **argv)
{
	char	*empty = "";
	if (argc == 3)
	{
		if (argv[1] == empty)
			write(1, "1", 1);
		else if (argv[2] == empty)
			write(1, "0", 1);
		else
			write(1, ft_check(argv[1], argv[2]), 1);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
