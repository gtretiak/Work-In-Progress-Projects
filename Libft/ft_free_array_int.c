/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:46:34 by gtretiak          #+#    #+#             */
/*   Updated: 2025/04/16 10:48:47 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array_int(int **arr, int len)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < len - 1)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}
