/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:38:05 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/06 13:51:05 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(char c, unsigned int x)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (c == 'x')
		base = "0123456789abcdef";
	if (x < 16)
		return (write(1, &base[x], 1));
	else
	{
		while (x >= 16)
		{
			count += ft_print_hex(c, (x / 16));
			count += ft_print_hex(c, (x % 16));
			x %= 16;
		}
	}
	return (count);
}
