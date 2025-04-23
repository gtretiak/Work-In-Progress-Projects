/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:52:22 by gtretiak          #+#    #+#             */
/*   Updated: 2025/01/30 17:57:51 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_word(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == 32 || s[i] == 9 || s[i] == 11))
		i++;
	while (s[i] && !(s[i] == 32 || s[i] == 9 || s[i] == 11))
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*empty;

	empty = "";
	if (argc == 2)
	{
		if (argv[1] == empty)
		{
			write(1, "\n", 1);
			return (0);
		}
		ft_put_word(argv[1]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
