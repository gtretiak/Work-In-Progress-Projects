/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:43:49 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/18 23:28:02 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_write(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	c = nb + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= -9 && nb <= 9)
		ft_write(nb);
	else
	{
		if (nb > 0)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
		{
			if (nb == -2147483648)
				write(1, "-2147483648", 11);
			else
			{
				write(1, "-", 1);
				ft_putnbr(-nb);
			}
		}
	}
}
/*
int	main(void)
{
	int	nb;

	nb = -4;
	printf("nb = %d\n", nb);
	ft_putnbr(nb);
}*/
