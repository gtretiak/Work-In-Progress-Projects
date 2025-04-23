/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:54:22 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 13:16:03 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
}
/*
int	main(void)
{
	size_t	n = 0;
	char	s[] = "hello";
//	ft_bzero(s, n);
//	printf("mine:%s", s);
	bzero(s, n);
	printf("orig:%s", s);
}*/
