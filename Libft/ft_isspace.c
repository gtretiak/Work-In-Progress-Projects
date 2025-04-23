/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:08:45 by gtretiak          #+#    #+#             */
/*   Updated: 2025/04/16 11:14:34 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (c);
	else
		return (0);
}
/*
int	main(void)
{
	char	c = '\b';
	printf("mine:%d\n", ft_isspace(c));
	printf("orig:%d\n", isspace(c));
}*/
