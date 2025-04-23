/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:25:27 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/22 15:49:10 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *n, int *n1)
{
	int	swap;

	swap = *n;
	*n = *n1;
	*n1 = swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	min;
	int	i;
	int	k;

	i = 0;
	while (i < size - 1)
	{
		min = tab[i];
		k = i + 1;
		while (k < size)
		{
			if (tab[k] < min)
				ft_swap(&tab[k], &min);
			++k;
		}
		if (tab[i] != min)
			ft_swap(&tab[i], &min);
		i++;
	}
}

int	main(void)
{
	int	x[] = {2, 5, -6, 0};
	printf("Before: %d, %d, %d, %d\n", x[0], x[1], x[2], x[3]);
	ft_sort_int_tab(x, (sizeof(x) / sizeof(x[0])));
	printf("After: %d, %d, %d, %d\n", x[0], x[1], x[2], x[3]);
}
