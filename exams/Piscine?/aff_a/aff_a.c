/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:33:04 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/07 21:32:15 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_write(int argc,char *str)
{
	if(argc != 2)
	{
		write(1,"a",1);
	}
	else
	{
		while (*str)
		{

			if (*str == 'a')
			{
				write(1, "a", 1);
				break;
			}
			str++;
		}
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	ft_write (argc,argv[1]);
}
