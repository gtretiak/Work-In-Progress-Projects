/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:38:11 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/21 15:35:14 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (!(*(str + i) >= 'a' && *(str + i) <= 'z'))
			if (!(*(str + i) >= 'A' && *(str + i) <= 'Z'))
				return (0);
		++i;
	}
	return (1);
}

int	main()
{
	char	str[30] = "Z";
	
	printf("%s / %s", str, (ft_str_is_alpha(str)) ? "1" : "0"); 
}
