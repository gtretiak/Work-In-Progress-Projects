#include <stdlib.h>
#include <stdio.h>

typedef struct s_pos
{
	int	start;
	int	end;
}	t_pos;

int	ft_strlen(char *str)
{
	int	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_free(int j, char **str)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

int	ft_count(char *str)
{
	int	i = 0;
	int	res = 0;
	while (str[i])
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 11))
			i++;
		if (str[i])
			res++;
		while (str[i] && (str[i] != 32 && 
		!(str[i] >= 9 && str[i] <= 11)))
			i++;
	}
	return (res);
}

int	ft_size_word(char *str, t_pos *pos)
{
	while (str[pos->start] && (str[pos->start] == 32 || 
		(str[pos->start] >= 9 && str[pos->start] <= 11)))
		pos->start++;
	pos->end = pos->start;
	while (str[pos->end] && str[pos->end] != 32 && 
		!(str[pos->end] >= 9 && str[pos->end] <= 11))
		pos->end++;
	return (pos->end - pos->start);
}

char	*ft_put_word(char *str, t_pos *pos, int len)
{
	char	*res;
	int	i = 0;
	res = malloc(sizeof(char) * len + 1); 
	if (!res)
		return (NULL);
	while (pos->start <= pos->end)
	{	
		res[i] = str[pos->start];
		i++;
		pos->start++; 
	}
	res[--i] = '\0';
	return (res);
}

char	**ft_split(char *str)
{
	int	words;
	int	j = 0;
	char **res;
	int	len;
	t_pos pos;
	pos.start = 0;
	pos.end = 0;
	if (!str)
		return (NULL);
	words = ft_count(str);
	res = malloc(sizeof(char *) * words + 1);
	if (!res)
		return (NULL);
	while (j < words)
	{
		len = ft_size_word(str, &pos);
		res[j] = ft_put_word(str, &pos, len);
		if (!res[j])
			ft_free(j, res);
		j++;
	}
	res[words] = NULL;
	return (res);
}
/*
int	main(void)
{
	char	*str = "four words are apart";
	char **arr = ft_split(str);
	printf("%s;%s;%s;%s;%s\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr[3]);
	free(arr[4]);
	free(arr);
	return (0);
}*/
