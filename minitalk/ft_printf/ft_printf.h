/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos <msantos@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:10:54 by msantos           #+#    #+#             */
/*   Updated: 2024/11/10 17:41:49 by msantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *type, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long number);
int	ft_putnbr_hexa(unsigned int n, int cap);
int	ft_print_ptr(unsigned long long ptr);
int	ft_ptr(unsigned long long ptr);

#endif
