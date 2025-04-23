/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:17:06 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/05 22:48:21 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b)
	{
		*div = a / b;
		*mod = a % b;
	}
}
/*
int	main ()
{
	int a;
	int b;
	int div;
	int mod;

	a = 75;
	b = 33;

	ft_div_mod(a, b, &div, &mod);
	if(b)
		printf("%d / %d = %d with remainder %d\n", a, b, div, mod);
	else
		printf("You can't divide by zero, try another value for b\n");
}*/
