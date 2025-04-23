/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:06:09 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/16 14:35:47 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countn(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_special(int n)
{
	char	*s;

	if (n == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	short	l;
	char	*s;

	if (n == 0 || n == -2147483648)
		return (ft_special(n));
	else
	{
		l = ft_countn(n);
		s = malloc(sizeof(char) * l + 1);
		if (!s)
			return (NULL);
		if (n < 0)
		{
			s[0] = '-';
			n = -n;
		}
		s[l] = '\0';
		while (n)
		{
			s[--l] = n % 10 + '0';
			n /= 10;
		}
		return (s);
	}
}
/*
int	main(void)
{
	char	*s;
	int	x;
	x = 0;
	s = ft_itoa(x);
	printf("%s", s);
	free(s);
}*/
