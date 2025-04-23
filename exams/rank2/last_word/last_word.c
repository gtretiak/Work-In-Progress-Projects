/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:30 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/06 12:22:42 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putword(char *str)
{
	int	i;
	int	l;

	l = ft_strlen(str);
	i = l - 1;
	while (str[i] && (str[i] == 32 || str[i] == 9 || str[i] == 11))
		i--;
	l = i;
	while (str[l] && str[l] != 32 && str[l] != 9 && str[l] != 11)
		l--;
	l++;
	while (l <= i)
		write(1, &str[l++], 1);
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
		write(1, "\n", 1);
	else
	{
		ft_putword(av[1]);
		write(1, "\n", 1);
	}
}
