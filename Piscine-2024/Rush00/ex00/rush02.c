/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:31:20 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/03 21:09:26 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(short x, short y)
{
	short	xi;
	short	yi;

	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			if (yi == 0 && (xi == 0 || xi == x - 1))
				ft_putchar('A');
			else if ((yi == 0 || yi == y - 1) && (xi != 0 && xi != x - 1))
				ft_putchar('B');
			else if (yi == y - 1 && (xi == 0 || xi == x - 1))
				ft_putchar('C');
			else if ((yi != 0 && yi != y - 1) && (xi == 0 || xi == x - 1))
				ft_putchar('B');
			else if (yi != 0 && yi != y - 1)
				ft_putchar(' ');
			xi++;
		}
		if (x > 0)
			ft_putchar('\n');
		yi++;
	}
}
