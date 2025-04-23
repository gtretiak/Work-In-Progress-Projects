/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:01:15 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/22 15:49:57 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_check_chars(char c, va_list args)
{
	char	*s;
	int		count;

	count = 0;
	if (c == 's')
	{
		s = va_arg(args, char *);
		if (s)
		{
			ft_putstr_fd(s, 1);
			return (count += ft_strlen(s));
		}
		else
			return (write(1, "(null)", 6));
	}
	else if (c == 'c')
	{
		c = (char)va_arg(args, int);
		ft_putchar_fd(c, 1);
		return (1);
	}
	else
		count += ft_check_numbers(c, args);
	return (count);
}
