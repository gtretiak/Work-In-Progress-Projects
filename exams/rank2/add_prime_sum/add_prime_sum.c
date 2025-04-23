/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:15:34 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/07 09:07:17 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign = 1;
	int	i = 0;
	int	n = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * sign);
}

void	ft_putnbr(int	n)
{
	char	c;
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_prime(int n)
{
	int	res = 0;
	int	i = 2;
	int	prime = 2;
	if (n <= 1)
		return ;
	while (prime <= n)
	{
		res = res + prime;
		prime++;
		while (prime % i == 0 && prime != i++)
			prime++;
	}
	ft_putnbr(res);
}

int	main(int ac, char **av)
{
	int	n;
	char	*str = "17";
	ac++;
	av[1] = str;
	if (1 > 2)	
//	if (ac != 2)
		write(1, "0\n", 1);
	else
	{
		n = ft_atoi(av[1]);
		if (n < 0)
			write(1, "0\n", 1);
		else
		{
			ft_prime(n);
			write(1, "\n", 1);
		}
	}
}
