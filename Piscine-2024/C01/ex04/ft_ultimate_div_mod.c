/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:39:50 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/05 13:35:58 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	store;

	if (*b)
	{
		store = *a;
		*a = *a / *b;
		*b = store % *b;
	}
}
/*
int	main()
{
	int	a;
	int	b;

	a = 999;
	b = 888;
	if(b)
	{
		printf("Values before operation: a = %d; b = %d\n", a, b);
		ft_ultimate_div_mod(&a, &b);
		printf("Values after operation: a = %d; b = %d\n", a, b);
	}
	else
		printf("You cannot divide by zero, try different value for b!");
}*/
