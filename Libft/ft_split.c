/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:05:30 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/27 12:10:37 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_free(char **arr, size_t j)
{
	size_t	i;

	i = 0;
	while (i <= j)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (1);
}

static int	ft_filler(char **arr, char const *s, char c, size_t num)
{
	size_t	i;
	size_t	j;
	size_t	l;

	j = 0;
	i = 0;
	while (j < num)
	{
		l = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			l++;
			i++;
		}
		arr[j] = ft_substr(s, i - l, l);
		if (!arr[j])
			return (ft_free(arr, j));
		j++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	num;

	if (!s)
		return (NULL);
	num = ft_countwords(s, c);
	arr = malloc(sizeof(char *) * (num + 1));
	if (!arr)
		return (NULL);
	if (ft_filler(arr, s, c, num))
		return (NULL);
	arr[num] = NULL;
	return (arr);
}
/*
int	main(void)
{
	int	i;
	char	**tabstr;
	if (!(tabstr = ft_split("xxxhello!", 'x')))
		printf("NULL");
	else
	{
		i = 0;
		while (tabstr[i] != NULL)
		{
			printf("%s", tabstr[i]);
			write(1, "\n", 1);
		        i++;
        	}
    	}
}*/
