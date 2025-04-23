/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:00:37 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 15:03:50 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if (*s1 != *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		if (*s1 == '\0')
			return (0);
		++s1;
		++s2;
		--n;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "hello\0";
	char	s2[] = "hello";
	size_t	n = 5;
	printf("mine:%d\n", ft_strncmp(s1, s2, n));
	printf("orig:%d\n", strncmp(s1, s2, n));
}*/
