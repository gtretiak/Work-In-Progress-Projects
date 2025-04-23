/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:01:36 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/21 15:24:13 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*(src + i) && n > i)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (n > i)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

int	main ()
{
	char	output[] = "BEEgfgfgssads";
	char	source[] = "0123453456789";
	unsigned int	length = 13;

	printf("Output by default: %s\nYour text: %s\n", output, source);
	printf("Output after: %s\n", ft_strncpy(output, source, length)); 
	printf("Call to function itself: %s", strncpy(output, source, length));
}
