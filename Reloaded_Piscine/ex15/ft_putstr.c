/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:52:19 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/15 09:04:04 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	short	i;

	i = 0;
	while (str[i])
		putchar(str[i++]);
}
/*
int	main(void)
{
	char	str[] = "Your text";
	ft_putstr(str);
}*/
