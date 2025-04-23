/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:43:54 by gtretiak          #+#    #+#             */
/*   Updated: 2024/11/11 17:28:48 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);

int	main(void)
{
	char	s[] = "!!ab!.cd!!!!!!(yz)!!!";
	char	c = '!';
	printf("str:%s\nchar:%c\n", s, c);
	printf("s1:%s\ns2:%s\ns3:%s\n", ft_split(s, c)[0], ft_split(s, c)[1], ft_split(s, c)[2]);
}
