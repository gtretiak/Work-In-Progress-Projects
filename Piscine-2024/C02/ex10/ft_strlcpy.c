/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:27:21 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/19 12:17:00 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int	main ()
{
	char    output[] = "";
        char    source[] = "abcde";
	unsigned int    len = sizeof(source) / sizeof(source[0]);

	printf("Output by default: %s\n", output);
        printf("Your text(source): %s\n", source);
        ft_strlcpy(output, source, len);
        printf("Output after: %s\n", output);
}*/
