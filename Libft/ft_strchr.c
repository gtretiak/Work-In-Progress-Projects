/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:19:46 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 14:59:53 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int	main(void)
{
	char	s[] = "0\vo";
	int	c = 11;
	printf("mine:%s\n", ft_strchr(s, c));
	printf("orig:%s\n", strchr(s, c));
}*/
