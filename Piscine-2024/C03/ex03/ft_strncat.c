/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:28:38 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/21 19:05:04 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[6] = "abc";
	char	s2[] = "..xyz";
	unsigned int	n;

	n = 3;
	printf("s1 = %s, s2 = %s, n = %d\n", s1, s2, n);
	printf("Res = %s\n", ft_strncat(s1, s2, n));
	printf("Call to function itself: %s", strncat(s1, s2, n));
}
