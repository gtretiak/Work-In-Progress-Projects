/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:34:44 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/14 19:41:07 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_is_negative(int n)
{
	char	p;
	char	o;

	p = 'P';
	o = 'N';
	if (n < 0)
		putchar(o);
	else
		putchar(p);
}
/*
int	main(void)
{
	ft_is_negative(92438298);
}*/
