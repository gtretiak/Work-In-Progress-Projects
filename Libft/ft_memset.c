/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:18:12 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 13:16:20 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = (unsigned char) c;
	return (s);
}
/*
int	main(void)
{
	char	c = '7';
	size_t	n = 7;
	char	so[] = "";
//	printf("mine:%s\n", (char *)ft_memset(so, c, n));
	printf("orig:%s\n", (char *)memset(so, c, n));
}*/
