/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:46:47 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/22 11:37:20 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void	ft_print(char c)
{
	write(1, &c, 1);
}

int	ft_recursion(int nbr, char *base, int base_size)
{
	long	l;

	l = nbr;
	if (l < 0)
	{
		l = -l;
		write(1, "-", 1);
	}
	if (l >= base_size)
		ft_recursion(l / base_size, base, base_size);
	ft_print(base[l % base_size]);
	return (0);
}

int	ft_double(char *base)
{
	short	i;
	short	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;

	base_size = 0;
	while (base[base_size])
	{
		if (base[base_size] == '+' || base[base_size] == '-')
			return ;
		base_size++;
	}
	if (base_size <= 1)
		return ;
	if (ft_double(base))
		return ;
	ft_recursion(nbr, base, base_size);
}

int	main(void)
{
	int	nbr = 12;
	
	char	base[] = "0123456789abcdef";
	printf("number:%d; system:%s\n", nbr, base);
	ft_putnbr_base(nbr, base);
}
