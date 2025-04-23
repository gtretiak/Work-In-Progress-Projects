/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:55:59 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 13:28:09 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	if (!dest && !src)
		return (dest);
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if (ptrsrc < ptrdest)
	{
		ptrdest += n;
		ptrsrc += n;
		while (n--)
			*(--ptrdest) = *(--ptrsrc);
	}
	else
	{
		while (n--)
			*ptrdest++ = *ptrsrc++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[] = "\0";
	char	src[] = "\0";
	size_t	n = 5;
	printf("mine:%s", (char *)ft_memmove(dest, src, n));
//	printf("orig:%s", (char *)memmove(dest, src, n));
}*/
