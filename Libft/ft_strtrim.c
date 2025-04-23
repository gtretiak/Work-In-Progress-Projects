/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:04:44 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/14 15:14:38 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int     ft_strcmp(char *s1, char *s2)
{
        int     i;
        int     res;

        i = 0;
        res = 0;
        while (s1[i] || s2[i])
        {
                if (s1[i] != s2[i])
                {
                        res = s1[i] - s2[i];
                        return (res);
                }
                else
                        i++;
        }
        return (res);
}
*/
static size_t	ft_check(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_newstr(const char *s1, size_t start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	l;

	if (!ft_strlen(s1))
		return (ft_strdup(""));
	i = 0;
	l = ft_strlen(s1) - 1;
	while (ft_check(set, s1[i]))
		i++;
	if (i == l + 1)
		return (ft_strdup(""));
	while (ft_check(set, s1[l]))
		l--;
	return (ft_newstr(s1, i, l - i + 1));
}
/*
int	main(void)
{
	char	*ret;
	char s1[] = "  \t \t \n   \n\n\n\t";
    	char s2[] = "";
	ret = ft_strtrim(s1, " \n\t");
	printf("good\n");
        printf("fail\n");
	free(ret);
}*/
