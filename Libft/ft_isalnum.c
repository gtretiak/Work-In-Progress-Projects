/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:32:01 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 12:13:43 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c))
		return (c);
	else if (ft_isdigit(c))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int	x;

	x = 66;
	printf("mine:%d\n", ft_isalnum(x));
	printf("orig:%d", isalnum(x));
}*/
