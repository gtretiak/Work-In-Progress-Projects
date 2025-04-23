/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:15:31 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/22 10:32:25 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			i++;
			continue;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10;
			res = res + str[i] - '0';
			i++;
		}
		i++;
	}
	return (res);
}

int	main(void)
{
	char	str[] = "1fgl2g	3";

	printf("str: %s\n", str);
	printf("res: %d\n", ft_atoi(str));
}
