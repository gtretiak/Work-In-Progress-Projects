/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:20:10 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/06 17:28:03 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32 ? 1 : 0);
}

int ft_isdigit(int c)
{
    return (c >= 48 && c <= 57 ? 1 : 0);
}

int ft_atoi(const char *str)
{
    int res = 0;
    int i = 0;
    int s = 1;
    
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
	    if (str[i] == '-')
		    s = -1;
	    i++;
    }
    while (ft_isdigit(str[i]))
    {
        res *= 10;
        res += str[i] - 48;
        i++;
    }
    return (res *= s);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*str = "+13268!";
	printf("%d", ft_atoi(str));
}*/
