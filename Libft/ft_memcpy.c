/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:55:06 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 13:22:10 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrsrc;
	unsigned char	*ptrdest;

	if (dest == NULL && src == NULL)
		return (dest);
	ptrsrc = (unsigned char *)src;
	ptrdest = (unsigned char *)dest;
	while (n--)
		*ptrdest++ = *ptrsrc++;
	return (dest);
}
/*
int	main(void)
{
	char	dest[] = "hello";
	const char	src[] = "hi!";
	size_t	n = 3;
//	printf("mine:%s", (char *)ft_memcpy(dest, src, n));
	printf("orig:%s", (char *)memcpy(dest, src, n));
}*/
