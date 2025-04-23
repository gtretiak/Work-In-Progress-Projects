/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:58:05 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 14:59:10 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			res = (char *)s;
		++s;
	}
	if ((unsigned char)c == '\0')
		res = (char *)s;
	return (res);
}
/*
int	main(void)
{
	char	s[] = "he\vllo";
	int	c = 11;
	printf("mine:%s\n", ft_strrchr(s, c));
	printf("orig:%s\n", strrchr(s, c));
}*/
