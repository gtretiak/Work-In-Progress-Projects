/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:46:37 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/14 19:54:47 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
/*
int	main(void)
{
	int	x;
	int	y;

	x = 21;
	y = 1000;
	printf("variables before:\nX = %d; Y = %d\n", x, y);
	ft_swap(&x, &y);
	printf("variables after:\nX = %d; Y = %d", x, y);
}*/
