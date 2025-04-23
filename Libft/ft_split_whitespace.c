/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:16:26 by gtretiak          #+#    #+#             */
/*   Updated: 2025/04/16 11:40:53 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(const char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		if (s[i])
			count++;
		while (s[i] && !ft_isspace(s[i]))
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

int	ft_filler(char **arr, char const *s, size_t num)
{
	size_t	i;
	size_t	j;
	size_t	l;

	j = 0;
	i = 0;
	while (j < num)
	{
		l = 0;
		while (ft_isspace(s[i]) && s[i])
			i++;
		while (!ft_isspace(s[i]) && s[i])
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

char	**ft_split_whitespace(char const *s)
{
	char	**arr;
	size_t	num;

	if (!s)
		return (NULL);
	num = ft_countwords(s);
	arr = malloc(sizeof(char *) * (num + 1));
	if (!arr)
		return (NULL);
	if (ft_filler(arr, s, num))
		return (NULL);
	arr[num] = NULL;
	return (arr);
}
/*
int	main(void)
{
	int	i;
	char	**tabstr;
	if (!(tabstr = ft_split_whitespace("x x x\nhello\f!	")))
		printf("NULL");
	else
	{
		i = 0;
		while (tabstr[i] != NULL)
		{
			printf("%d:%s\n", i + 1, tabstr[i]);
		        i++;
        	}
    	}
}*/
