/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:28:26 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/22 17:07:01 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char c)
{
	write(1, &c, 1);
}

int	ft_counter(char c)
{
	int	repeat;
	if (c >= 'A' && c <= 'Z')
		repeat = c - 'A' + 1;
	else if (c >= 'a' && c <= 'z')
		repeat = c - 'a' + 1;
	else
		repeat = 1;
	return (repeat);
}

int	main (int argc, char *argv[])
{
	int	i;
	int	repeat;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			repeat = ft_counter(argv[1][i]);
			while (repeat)
			{
				ft_write(argv[1][i]);
				--repeat;
			}
			i++;
		}
	}
	ft_write('\n');
	return (0);
}
