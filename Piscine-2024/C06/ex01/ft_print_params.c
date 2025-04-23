/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:57:56 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/22 12:13:10 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_write(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	s;
	short	i;
	short	j;

	i = 1;
	s = argc;
	while (s > 1)
	{
		j = 0;
		while (argv[i][j])
		{
			ft_write(argv[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
		s--;
	}
}
