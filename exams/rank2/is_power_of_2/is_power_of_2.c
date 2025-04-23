/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:18:31 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/06 15:52:57 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return (!(n & (n - 1)));
/*	if (n == 1)
		return (1);
	while (n > 1 && n % 2 == 0)
		n /= 2;
	if (n == 1)
		return (1);
	else
		return (0);*/
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned int	n = 0;
	printf("%d", is_power_of_2(n));
}*/
