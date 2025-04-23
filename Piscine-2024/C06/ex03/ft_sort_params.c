/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:21:27 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/21 11:03:42 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void	ft_write(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

// Here we have addresses of the strings (of the pointers to pointers)
void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

// We compare elements inside 2strings while we have smth in the1
// we increment position in the string by incrementing the address
// if the 1string has a value bigger than the2 ... we swap the whole strings
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

// Here we compare whole strings (arrays)
// Here we swap addresses of these whole strings (arrays)
void	ft_sort(int amount, char *argv[])
{
	int	i;
	int	j;
	int	l;

	l = amount;
	while (l > 0)
	{
		i = 0;
		j = 1;
		while (j < amount)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				ft_swap (&argv[i], &argv[j]);
			i++;
			j++;
		}
		l--;
	}
}

// we pass the array of arrays (pointer to the pointer of the1 array)
// pointer to the second element in the array of pointers, skipping a.out
// While smth inside arr of arrays or while pointer doesn't point to NULL
// we call ft_write with this arrays
int	main(int argc, char *argv[])
{
	ft_sort(argc - 1, argv + 1);
	while (*(++argv))
		ft_write(*argv);
}
