/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:17:20 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/15 09:18:56 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	res;

	res = 1;
	if (nb > 0)
	{
		while (res * res < nb)
			++res;
		if (res * res == nb)
			return (res);
	}
	return (0);
}
/*
int	main(void)
{
	int	x;

	x = 4;
	printf("X = %d\n", x);
	printf("square root is %d\n", ft_sqrt(x));
}*/
