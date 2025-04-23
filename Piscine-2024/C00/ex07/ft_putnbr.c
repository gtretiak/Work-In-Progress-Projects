/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:32:49 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/03 13:41:38 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int nb)
{
	char	c;

	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	c = nb + '0';
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > -10 && nb < 10)
		ft_write(nb);
	else
	{
		if (nb > 0)
		{
			ft_putnbr (nb / 10);
			ft_putnbr (nb % 10);
		}
		else
		{
			if (nb == -2147483648)
				write(1, "-2147483648", 11);
			else
			{
				write (1, "-", 1);
				ft_putnbr(-nb);
			}
		}
	}
}
/*
int	main(void)
{
	ft_putnbr(42);
}*/
