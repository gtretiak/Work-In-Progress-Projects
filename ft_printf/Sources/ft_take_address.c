/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:42:28 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/22 17:19:17 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_take_address(void *arg)
{
	int			count;
	uintptr_t	address;

	count = 0;
	if (!arg)
		return (write(1, "(nil)", 5));
	address = (uintptr_t)arg;
	count += write(1, "0x", 2);
	count += ft_print_address(address);
	return (count);
}
