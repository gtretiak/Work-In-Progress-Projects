/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:29:30 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/15 10:01:04 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	short	j;
	short	k;

	j = 1;
	while (j < argc)
	{
		k = 0;
		while (argv[j][k])
		{
			putchar(argv[j][k]);
			k++;
		}
		putchar('\n');
		j++;
	}
	return (0);
}
