/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:26:01 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/21 18:55:29 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char	s1[] = "abcde";
	char	s2[] = "ab12e";
	unsigned int	x;

	x = 2;
	printf("s1 = %s, s2 = %s, n = %d\n", s1, s2, x);
	printf("res of comparison = %d\n", ft_strncmp(s1, s2, x));
	printf("Call to original function: %d", strncmp(s1, s2, x));
}
