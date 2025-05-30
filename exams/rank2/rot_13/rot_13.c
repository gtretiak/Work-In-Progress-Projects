/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:46:21 by gtretiak          #+#    #+#             */
/*   Updated: 2024/12/27 18:59:12 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 97 && argv[1][i] <= 109)
				argv[1][i] += 13;
			else if (argv[1][i] >= 110 && argv[1][i] <= 122)
				argv[1][i] -= 13;
			else if (argv[1][i] >= 65 && argv[1][i] <= 77)
				argv[1][i] += 13;
			else if (argv[1][i] >= 78 && argv[1][i] <= 90)
				argv[1][i] -= 13;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
