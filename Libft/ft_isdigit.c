/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:39 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/18 12:08:19 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c < 58)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int	x = 57;
	printf("mine:%d\n", ft_isdigit(x));
	printf("orig:%d", isdigit(x));
}*/
