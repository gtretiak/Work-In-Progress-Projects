/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:51:23 by gtretiak          #+#    #+#             */
/*   Updated: 2024/08/21 18:49:44 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_upper(char *str, short i)
{
	if (str[i - 1] >= 32 && str[i - 1] <= 47)
	{
		if (str[i - 1] >= 58 && str[i - 1] <= 64)
		{	if (str[i - 1] >= 91 && str[i - 1] <= 96)
			{	if (str[i - 1] >= 123 && str[i - 1] <= 126)
				{	if (i == 0)
						return (str);
				}
			}
		}
	}
	str[i] -= 32;
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			if (i != 0 && str[i - 1] != 32)
				str[i] += 32;
			else if (!(str[i - 1] >= 48 && str[i - 1] <= 57))
				str[i] += 32;
		}
		else if (str[i] >= 97 && str[i] <= 122)
			ft_upper(str, i);
		i++;
	}
	return (str);
}

int	main(void)
{
	char	str[70] = "HEL Переводiomt tu va ? 42mo qu-de; ciu+et+un";
	printf ("Text before:\n%s\n", str);
	printf ("Text after:\n%s", ft_strcapitalize(str));
}
