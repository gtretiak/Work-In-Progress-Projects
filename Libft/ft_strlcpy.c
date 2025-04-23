/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:56:44 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/22 12:28:02 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (len + 1 < size)
		ft_memcpy(dest, src, len + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (len);
}
/*
#include <bsd/string.h>

int	main(void)
{
	char	dest[6] = "hhjhh";
	char	src[4] = "mor";
	char	dest2[6] = "hhjhh";
	char	src2[4] = "mor";
	size_t	size;

	size = 2;
	printf("mine:%zu\n", ft_strlcpy(dest, src, size));
	printf("%s\n",dest);
	printf("orig:%zu\n", strlcpy(dest2, src2, size));
	printf("%s\n",dest2);
}*/
