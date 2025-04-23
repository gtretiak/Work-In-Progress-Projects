/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:59:01 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 15:42:36 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;

	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	while (n--)
	{
		if (*ptrs1 != *ptrs2)
			return (*ptrs1 - *ptrs2);
		ptrs1++;
		ptrs2++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "hello";
	char	s2[] = "helli";
	size_t	n = 0;
	printf("mine:%d\n", ft_memcmp(s1, s2, n));
	printf("orig:%d\n", memcmp(s1, s2, n));
}*/
