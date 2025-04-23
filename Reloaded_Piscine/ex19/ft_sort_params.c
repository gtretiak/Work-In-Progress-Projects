/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:02:44 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/15 11:11:25 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(char **s1, char **s2)
{
	char	*swap;

	swap = *s1;
	*s1 = *s2;
	*s2 = swap;
}

int	ft_strcmp(char *s1, char *s2)
{
	short	i;
	short	k;

	i = 0;
	k = 0;
	while (s1[i] && s1[i] == s2[k])
	{
		i++;
		k++;
	}
	return (s1[i] - s2[k]);
}

void	ft_sort(int args, char **argv)
{
	short	i;
	short	k;

	while (args - 1)
	{
		i = 0;
		k = 1;
		while (k < args)
		{
			if (ft_strcmp(argv[i], argv[k]) > 0)
				ft_swap(&argv[i], &argv[k]);
			++i;
			++k;
		}
		--args;
	}
}

int	main(int argc, char **argv)
{
	short	i;
	short	k;

	ft_sort(argc - 1, argv + 1);
	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k])
		{
			putchar(argv[i][k]);
			k++;
		}
		putchar('\n');
		i++;
	}
}
