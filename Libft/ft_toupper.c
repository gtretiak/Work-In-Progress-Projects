/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:39:59 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 14:27:05 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c -= 32);
	else
		return (c);
}
/*
int	main(void)
{
	int	x = 9;
	printf("mine:%d\n", ft_toupper(x));
	printf("orig:%d\n", toupper(x));
}*/
