/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:47:56 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/06 15:13:34 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*res;
	if (nbr == -2147483648)
	{
		res = "-2147483648";
		return (res);
	}
	int	size = 1;
	int	sign = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		sign = 1;
	}
	int	tmp = nbr;
	int	i = 0;
	while (tmp >= 10)
	{
		tmp /= 10;
		size++;
	}
	size += sign;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (sign == 1)
		res[0] = '-';
	while (size - 1 - i >= sign)
	{
		res[size - 1 - i] = nbr % 10 + '0';
		nbr /= 10;
		i++;
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	int	nbr = -2147483648;
	char	*s = ft_itoa(nbr);
	printf("nbr:%d\nstr:%s\n", nbr, s);
}*/
