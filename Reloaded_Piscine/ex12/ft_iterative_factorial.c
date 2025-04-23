/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:06:49 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/14 23:31:46 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	x;	

	x = nb - 1;
	if (nb > 0 && nb < 13)
	{
		while (x)
			nb = nb * x--;
		return (nb);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int	x;

	x = 0;
	printf("x = %d\n", x);
	ft_iterative_factorial(x);
}*/
