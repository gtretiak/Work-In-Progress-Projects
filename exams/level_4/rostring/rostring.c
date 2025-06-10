#include <stdlib.h>
#include <unistd.h>

int	ft_count_words(char *str)
{
	int words = 0;
	int	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || (str[i] == 9 || str[i] <= 11)))
			i++;
		if (str[i])
			words++;
		while (str[i] && !(str[i] == 32 || (str[i] == 9 || str[i] == 11)))
			i++;
	}
	return (words);
}

/*int	ft_strlen(char *str, int words)
{
	int	i = 0;
	while (str[i] && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	i = i + words - 1;
	return (i);
}*/

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_meat(char	*str, int	len)
{	
	int	j = 0;
	int	i = 0;
	int	start;
	int	stop;
	char	*res;
	res = NULL;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (str[i] == 32 || (str[i] == 9 || str[i] == 11))
		i++;
	start = i;
	while (str[i] != 32 && !(str[i] == 9 || str[i] == 11))
		i++;
	stop = i;
	while (str[i])
	{
		while (str[i] == 32 || (str[i] == 9 || str[i] == 11))
			i++;
		while (str[i] && !(str[i] == 32 || (str[i] == 9 || str[i] == 11)))
			res[j++] = str[i++];	
		if (str[i] && str[i + 1])
			res[j++] = ' ';
	}
	res[j++] = ' ';
	while (start < stop)
		res[j++] = str[start++];
	res[j] = '\0'; 
	return (res);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	int	words;
	int	len;
	char	*res = NULL;
	char	*tmp = NULL;
//	char	*str = "abc   ";
//	argv[1] = str;
//	argc++;
//	if (1)
	if (argc > 1)
	{
		words = ft_count_words(argv[1]);
		if (words == 0)
			write(1, "\n", 1);
		else if (words == 1)
		{
			while (argv[1][i])
			{
				if (argv[1][i] != 32 && argv[1][i] != 9 && argv[1][i] != 11)
					write(1, &argv[1][i], 1);
				i++;
			}
			write(1, "\n", 1);
		}
		else
		{
			len = ft_strlen(argv[1]);
			//len = ft_strlen(argv[1], words);
			res = ft_meat(argv[1], len);
			if (!res)
				return (0);
			tmp = res;
			while (*tmp)
				write(1, tmp++, 1);
			free(res);
			res = NULL;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
}
