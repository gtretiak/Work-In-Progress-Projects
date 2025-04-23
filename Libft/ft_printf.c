/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:40:29 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/06 13:51:14 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	if (!format)
		return (write (1, "(null)", 6));
	while (*format)
	{
		if (*format == '%')
			count += ft_check_chars(*(++format), args);
		else
		{
			ft_putchar_fd(*(char *)format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
