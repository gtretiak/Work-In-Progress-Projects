/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:44:04 by gtretiak          #+#    #+#             */
/*   Updated: 2025/04/16 10:54:13 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array_str(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	ft_free_array_strn(char **arr, int n)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < n)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}
