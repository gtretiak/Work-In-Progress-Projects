/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:11:12 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/15 09:28:59 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	short	i;
	short	j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}
/*
int	main(void)
{
	char	s1[] = "";
	char	s2[] = "\b";
	printf("s1 = %s\ns2 = %s\n", s1, s2);
	printf("res = %d\n", ft_strcmp(s1, s2));
	printf("Original:%d", strcmp(s1, s2));
}*/
