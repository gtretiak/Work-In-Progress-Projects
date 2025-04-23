/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:03:55 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 11:59:40 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int	main(void)
{
	char	*s1 = NULL;
	char	*s2 = "world";
	char	*mine = ft_strjoin(s1, s2);
	printf("%s", mine);
}*/
