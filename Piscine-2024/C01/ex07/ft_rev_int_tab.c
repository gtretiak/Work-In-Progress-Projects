/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:11:28 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/21 14:18:59 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	swap;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		swap = *(tab + i);
		*(tab + i) = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = swap;
		i++;
	}
}

int	main(void)
{
	int	arr[] = {5, 0, -6, 56, 1239};

	printf("BEFORE: %d, %d, %d, %d, %d\n", *(arr + 0), *(arr + 1), *(arr + 2), *(arr + 3), *(arr + 4));
	ft_rev_int_tab(arr, 5);
	printf("AFTER: %d, %d, %d, %d, %d\n", *(arr + 0), *(arr + 1), *(arr + 2), *(arr + 3), *(arr + 4));
}
