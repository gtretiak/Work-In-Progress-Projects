/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:26:34 by gtretiak          #+#    #+#             */
/*   Updated: 2025/02/06 19:17:38 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	fill(char **tab, t_point size, char c, int row, int col)
{
	if (row < 0 || row >= size.y || col < 0 || col >= size.x)
		return ;
	if (tab[row][col] == 'F' || tab[row][col] != c)
		return ;
	tab[row][col] = 'F';
	fill(tab, size, c, row - 1, col);
	fill(tab, size, c, row + 1, col);
	fill(tab, size, c, row, col + 1);
	fill(tab, size, c, row, col - 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;

	c = tab[begin.y][begin.x];
	fill(tab, size, c, begin.y, begin.x);
}
/*
#include <stdlib.h>
#include <unistd.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

void	ft_putstr(char	*str)
{
	while (*str)
		write(1, str++, 1);
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
	{
		ft_putstr(area[i]);
		write(1, "\n", 1);
	}
	write(1, "\n\n", 2);
	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
	{
		ft_putstr(area[i]);
		write(1, "\n", 1);
	}
	return (0);
}*/
