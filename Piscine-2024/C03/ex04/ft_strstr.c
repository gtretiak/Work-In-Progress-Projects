/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:39:00 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/22 10:13:31 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	short	i;
	short	j;

	i = 0;
	j = 0;
	if (!to_find[0])
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
				j++;
			if (!to_find[j])
				return (&str[i]);
			j = 0;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	s1[] = "I want to pass";
	char	s2[] = "to";
	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("res = %s\n", ft_strstr(s1, s2));
	printf("Call to function itself: %s", strstr(s1, s2));
}
