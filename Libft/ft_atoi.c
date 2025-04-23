/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:01:11 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 15:50:22 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	n;
	short	s;

	i = 0;
	n = 0;
	s = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			s++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n = n + str[i] - '0';
		i++;
	}
	if (s > 0)
		n = -n;
	return (n);
}
/*
int	main(void)
{
	char	*s;

	s = "-520";
	printf("mine:%i\n", ft_atoi(s));
	printf("orig:%i", atoi(s));
}*/
