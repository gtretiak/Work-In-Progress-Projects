/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:11:38 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/22 11:49:24 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_write(char c)
{
	write(1, &c, 1);
}

int	ft_rec(int nbr, char *base, int size)
{
	long	l;
	l = nbr;
	if (l < 0)
	{
		l = -l;
		ft_write('-');
	}
	if (l >= size)
		ft_rec(l / size, base, size);
	ft_write(base[l % size]);
	return (0);	
}

int	ft_double(char *base)
{
	short	i = 0;
	short	j;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_put(int nbr, char *base)
{
	int	size = 0;
	while (base[size])
		size++;
	if (size <= 1)
		return ;
	if (ft_double(base))
		return ;
	ft_rec(nbr, base, size);
}

int	main(void)
{
	int	nbr = 42;
	char	base[] = "42Lisbon";
	printf("%d; %s\n", nbr, base);
	ft_put(nbr, base);
}
