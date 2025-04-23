/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:55:37 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/22 17:49:33 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_check_numbers(char c, va_list args)
{
	int		count;
	char	*s;

	count = 0;
	if (c == 'i' || c == 'd')
	{
		s = ft_itoa(va_arg(args, int));
		ft_putstr_fd(s, 1);
		count += ft_strlen(s);
		free(s);
	}
	else if (c == 'u')
	{
		s = ft_unitoa(va_arg(args, unsigned int));
		ft_putstr_fd(s, 1);
		count += ft_strlen(s);
		free(s);
	}
	else if (c == 'x' || c == 'X')
		count += ft_print_hex(c, va_arg(args, unsigned int));
	else
		count += ft_check_else(c, args);
	return (count);
}
