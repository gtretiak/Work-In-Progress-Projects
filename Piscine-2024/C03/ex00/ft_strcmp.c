/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:52:28 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/21 18:55:14 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			return (res);
		}
		else
			i++;
	}
	return (res);
}

int	main ()
{
	char	s1[] = "aecde";
	char	s2[] = "";

	printf("s1 = %s\ns2 = %s\n", s1, s2);
	printf("result of comparison = %d\n", ft_strcmp(s1, s2));
	printf("Call to original function: %d\n", strcmp(s1, s2));
}
