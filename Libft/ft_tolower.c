/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:32 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 13:59:51 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c += 32);
	else
		return (c);
}
/*
int	main(void)
{
	int	x = 358723;
	printf("mine:%d\n", ft_tolower(x));
	printf("orig:%d\n", tolower(x));
}*/
