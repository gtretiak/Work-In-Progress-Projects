/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:16:25 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/07 19:14:04 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	ft_atoi(char *str)
{
	int	i;
	int	odd_even;
	int	res;

	i = 0;
	odd_even = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			odd_even++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	if (odd_even % 2)
		return (-res);
	return (res);
}

int	main(void)
{
	char	str[] = "\n	\f\v \r\t+--+--74839255567	d";
	printf("str: %s\n", str);
	printf("My function returns: %d\n", ft_atoi(str));
}
