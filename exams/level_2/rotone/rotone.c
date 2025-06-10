/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:32:08 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/22 17:42:14 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char c)
{
	write(1, &c, 1);
}

void	ft_sort(char c)
{
	if (c >= 'a' && c <= 'y')
		c += 1;
	else if (c >= 'A' && c <= 'Y')
		c += 1;
	else if (c == 'Z' || c == 'z')
		c -= 25;
	ft_write(c);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			ft_sort(argv[1][i]);
			i++;
		}
	}
	ft_write('\n');
	return (0);
}
