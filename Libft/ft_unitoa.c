/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:58 by gtretiak          #+#    #+#             */
/*   Updated: 2025/03/06 13:49:59 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countn(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_unitoa(unsigned int n)
{
	short	l;
	char	*s;

	l = ft_countn(n);
	s = malloc(sizeof(char) * l + 1);
	if (!s)
		return (NULL);
	s[l] = '\0';
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	while (n)
	{
		s[--l] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
