/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:55:36 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/06 14:45:50 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_put_hex(long nb)
{
	char	*base = "0123456789abcdef";
	if (nb <= 15)
	       write(1, &base[nb], 1);
	else
	{
		ft_put_hex(nb / 16);
		ft_put_hex(nb % 16);
	}	
}

long	ft_atoi(char *str)
{
	long	n = 0;
	int	i = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		n = n * 10 + str[i++] - '0';
	return (n);
}

int	main(int ac, char **av)
{
//	char	*input = "10";
//	av[1] = input;
//	ac++;
	long	nb;
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		nb = ft_atoi(av[1]);
		ft_put_hex(nb);
		write(1, "\n", 1);
	}
}
