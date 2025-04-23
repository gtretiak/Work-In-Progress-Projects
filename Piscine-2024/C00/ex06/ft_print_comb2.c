/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:09:39 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/17 19:34:18 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_write_2(short a, short b)
{
	char	ca1;
	char	ca2;
	char	cb1;
	char	cb2;

	ca1 = a / 10 + '0';
	ca2 = a % 10 + '0';
	cb1 = b / 10 + '0';
	cb2 = b % 10 + '0';
	write (1, &ca1, 1);
	write (1, &ca2, 1);
	write (1, " ", 1);
	write (1, &cb1, 1);
	write (1, &cb2, 1);
	if (!(ca1 == '9' && ca2 == '8' && cb1 == '9' && cb2 == '9'))
		write (1, ", ", 2);
}

void	ft_print_comb2(void)
{
	short	a;
	short	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_write_2 (a, b);
			b++;
		}
		a++;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
}*/
