/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:58:12 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 15:40:05 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptrs;

	ptrs = (unsigned char *)s;
	while (n--)
	{
		if (*ptrs == (unsigned char)c)
			return (ptrs);
		ptrs++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "hello";
	int	c = 1208;
	size_t	n = 0;
	printf("mine:%s\n", (char *)ft_memchr(s, c, n));
	printf("orig:%s\n", (char *)memchr(s, c, n));
}*/
