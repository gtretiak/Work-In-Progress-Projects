/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:04 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/22 17:50:08 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int		ft_print_address(unsigned long x);
int		ft_print_hex(char c, unsigned int x);
int		ft_take_address(void *arg);
char	*ft_unitoa(unsigned int n);
int		ft_check_else(char c, va_list args);
int		ft_check_numbers(char c, va_list args);
int		ft_check_chars(char c, va_list args);
int		ft_printf(const char *format, ...);

#endif
