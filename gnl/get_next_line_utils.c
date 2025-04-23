/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:27:24 by gtretiak          #+#    #+#             */
/*   Updated: 2024/12/12 17:38:47 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*s;
	char	*temp;

	l = 0;
	temp = (char *)s1;
	while (s1[l])
		l++;
	s = malloc(sizeof(char) * (l + 1));
	if (s == NULL)
		return (NULL);
	temp = s;
	while (*s1)
		*temp++ = *s1++;
	*temp = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)s;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s + start);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (len > i)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*joined;
	size_t	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	while (str1[i])
	{
		joined[i] = str1[i];
		i++;
	}
	while (*str2)
		joined[i++] = *str2++;
	joined[i] = '\0';
	return (joined);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (!(*s))
			return (NULL);
		s++;
	}
	return ((char *)s);
}
