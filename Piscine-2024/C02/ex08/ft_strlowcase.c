/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:42:01 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/21 15:41:46 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strlowcase(char *str)
{
	short	i;

	i = 0;
	while (*(str + i))
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return (str);
}

int     main ()
{
	char	str[30] = "aAbBcCdD123&!";
	
	printf("Text before: %s\n", str);
	printf(" Text after: %s", ft_strlowcase(str));
}
