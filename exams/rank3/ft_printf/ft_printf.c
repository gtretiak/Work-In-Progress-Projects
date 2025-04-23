/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:17:42 by gtretiak          #+#    #+#             */
/*   Updated: 2025/04/06 15:57:30 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>

int	ft_print_hex(unsigned int num)
{
	int	res;
	char	*base;

	res = 0;
	base = "0123456789abcdef";
	if (num < 16)
		res += write(1, &base[num], 1);
	else
	{
		res += ft_print_hex(num / 16);
		res += ft_print_hex(num % 16);
	}
	return (res);
}

int	ft_print_num(int num)
{
	int	res;
	char	c;

	res = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		res += write(1, "-", 1);
		num *= -1;
	}
	if (num < 10)
	{
		c = num + '0';
		res += write(1, &c, 1);
	}
	else
	{
		res += ft_print_num(num / 10);
		res += ft_print_num(num % 10);
	}
	return (res);
}

int	ft_print_str(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_check_format(va_list ap, char c)
{
	int	res;

	res = 0;
	if (c == 'd')
		res += ft_print_num(va_arg(ap, int));
	else if (c == 's')
		res += ft_print_str(va_arg(ap, char *));
	else if (c == 'x')
		res += ft_print_hex(va_arg(ap, unsigned int));
	else
		res += write(1, &c, 1);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int	res;
	va_list	ap;

	if (!format)
		return (write(1, "(null)", 6));
	res = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			res += ft_check_format(ap, *(++format));
		else
			res += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (res);
}
/*
int	main(void)
{
	int	res;
	res = ft_printf("My string %s\n", "hello");
	printf("My:%d\n", res);
	res = ft_printf("Or string %s\n", "hello");
	printf("Or:%d\n", res);
	res = ft_printf("My digit %d\n", -12312342);
	printf("My:%d\n", res);
	res = ft_printf("Or digit %d\n", -12312342);
	printf("Or:%d\n", res);
	res = ft_printf("My hex %x\n", -12312342);
	printf("My:%d\n", res);
	res = ft_printf("Or hex %x\n", -12312342);
	printf("Or:%d\n", res);
	res = ft_printf("%s\n", "toto");
	printf("My:%d\n", res);
	res = printf("%s\n", "toto");
	printf("Or:%d\n", res);
	res = ft_printf("Magic %s is %d\n", "number", 42);
	printf("My:%d\n", res);
	res = printf("Magic %s is %d\n", "number", 42);
	printf("Or:%d\n", res);
	res = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("My:%d\n", res);
	res = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Or:%d\n", res);
}*/
