/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos <msantos@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:04:14 by msantos           #+#    #+#             */
/*   Updated: 2024/11/10 18:01:30 by msantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

static int	istypevalid(char c)
{
	char	*types;

	types = "cspdiuxX%";
	while (*types)
	{
		if (c == *types)
			return (1);
		types++;
	}
	return (0);
}

static int	print_type(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(*args, int));
	else if (c == '%')
		count = ft_putchar('%');
	else if (c == 's')
		count = ft_putstr(va_arg(*args, char *));
	else if (c == 'i' || c == 'd')
		count = ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		count = ft_putnbr(va_arg(*args, unsigned int));
	else if (c == 'x')
		count = ft_putnbr_hexa(va_arg(*args, unsigned int), 0);
	else if (c == 'X')
		count = ft_putnbr_hexa(va_arg(*args, unsigned int), -32);
	else if (c == 'p')
		count = ft_ptr(va_arg(*args, unsigned long long));
	return (count);
}

int	ft_printf(const char *type, ...)
{
	size_t	i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, type);
	while (type[i])
	{
		if (type[i] == '%' && type[i + 1] && istypevalid(type[i + 1]))
			count += print_type(&args, type[++i]);
		else
			count += ft_putchar(type[i]);
		i++;
	}
	va_end(args);
	return (count);
}
