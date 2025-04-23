/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:56:27 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/14 20:06:11 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 430;
	b = 21;
	div = 666;
	mod = 666;
	printf("a = %d; b = %d\nBEFORE: Div = %d; Mod = %d\n", a, b, div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("AFTER:\nDIV = %d; MOD = %d", div, mod);
}*/
