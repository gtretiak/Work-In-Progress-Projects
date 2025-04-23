/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:11:13 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/22 12:23:25 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_write(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	s;
	int	i;
	int	j;

	s = argc;
	i = s - 1;
	while (i > 0)
	{
		j = 0;
		while (argv[i][j])
		{
			ft_write(argv[i][j]);
			j++;
		}
		ft_write('\n');
		i--;
	}
}
