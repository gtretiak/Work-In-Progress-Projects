/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:57:31 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 13:43:37 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	if (size <= i)
		return (size + j);
	k = 0;
	while (size > i + k + 1 && src[k])
	{
		dest[i + k] = src[k];
		k++;
	}
	if (i + k < size)
		dest[i + k] = '\0';
	return (i + j);
}
/*
#include <bsd/string.h>

int	main(void)
{
	char	dest[] = "hel0";
	char	src[] = "\0";
	size_t	n = 55;
//	printf("mine:%zu", ft_strlcat(dest, src, n));
	printf("orig:%zu", strlcat(dest, src, n));
}*/
