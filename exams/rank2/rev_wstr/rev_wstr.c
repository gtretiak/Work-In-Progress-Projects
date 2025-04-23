/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:28:23 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/06 13:41:59 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_countwords(char *str)
{
	int count = 0;
	int	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == 9 || str[i] == 11))
			i++;
		if (str[i])
		{
			count++;
		}
		while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != 11)
			i++;
	}
	return (count);
}

char	*ft_insert(char *str, int start, int end)
{
	char	*res;
	int	i = 0;
	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	while (start + i <= end)
	{
		res[i] = str[start + i];
		i++;
	}
	res[end + 1] = '\0';
	return (res);
}

void	ft_free(char **arr, int j)
{
	int	i = 0;
	while (i <= j)
		free(arr[i++]);
	free(arr);
}

char	**ft_fill_arr(char *str, int words)
{
	int	i = 0;
	int	j = 0;
	int	start = 0;
	int	end = 0;
	char	**res;
	res = malloc(sizeof(char *) * words + 1);
	if (!res)
		return (NULL);
	while (j < words)
	{
		while (str[i] && (str[i] == 32 || str[i] == 9 || str[i] == 11))
			i++;
		start = i;
		while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != 11)
			i++;
		end = i - 1;
		res[j] = ft_insert(str, start, end);
		if (!res[j])
			ft_free(res, j);
		j++;
	}
	res[j] = NULL;
	return (res);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print(char **arr, int words)
{
	int	i = words;
	while (i - 1 >= 0)
	{
		ft_putstr(arr[--i]);
		if (i - 1 >= 0)
			write(1, " ", 1);
	}
}

void	ft_rev(char *str)
{
	char	**arr;
	int	words = ft_countwords(str);
	if (words == 0)
		return ;
	arr = ft_fill_arr(str, words);
	if (!arr)
		return ;
	ft_print(arr, words);
	ft_free(arr, words - 1);
}

int	main(int ac, char **av)
{
//	char *str = "You hate people! But I love gatherings. Isn't it ironic?";
//	av[1] = str;
//	ac++;
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		ft_rev(av[1]);
		write(1, "\n", 1);
	}
}
