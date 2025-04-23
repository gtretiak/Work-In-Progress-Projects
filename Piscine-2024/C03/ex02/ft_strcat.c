/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:39:36 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/21 19:02:43 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	short	i;
	short	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest [i + j] = '\0';
	return (dest);
}

int	main()
{
	char	s1[10] = "abc";
	char	s2[6] = "..xyz";
	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("res = %s\n", ft_strcat(s1, s2));
	printf("Call to function itself = %s", strcat(s1, s2));
}
