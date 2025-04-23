/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:28:03 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 12:06:08 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (c);
	else
		return (0);
}
/*
int	main(void)
{
	int	x = 66;
	printf("mine:%d\n", ft_isalpha(x));
	printf("orig:%d\n", isalpha(x));
}*/
