/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:31:37 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/15 09:10:07 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	res;

	res = 0;
	while (*(str))
	{
		res++;
		str++;
	}
	return (res);
}

int	main ()
{
	char	*x;

	x = "\n\r\b\v";
	printf("%d", ft_strlen(x));
}
