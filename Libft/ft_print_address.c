/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:38:05 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/06 13:50:17 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_address(unsigned long x)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (x < 16)
		return (write(1, &base[x], 1));
	else
	{
		while (x >= 16)
		{
			count += ft_print_address(x / 16);
			count += ft_print_address(x % 16);
			x %= 16;
		}
	}
	return (count);
}
