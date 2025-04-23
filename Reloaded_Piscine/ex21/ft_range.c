/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:52:05 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/15 15:56:35 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_calc(int min, int max)
{
	int	i;

	i = 1;
	while (min < max)
	{
		++min;
		++i;
	}
	return (i);
}

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	l;

	if (min >= max)
		return (0);
	l = ft_calc(min, max);
	arr = malloc(sizeof(int) * l);
	i = 0;
	while (i != l)
	{
		arr[i] = min;
		i++;
		min++;
	}
	i = 0;
	return (arr);
}
/*
int	main(void)
{
	int	min = 2;
	int	max = 10;

	printf("min:%d;\n", min);
	printf("max:%d;\n", max);
	ft_range(min, max);
}*/
