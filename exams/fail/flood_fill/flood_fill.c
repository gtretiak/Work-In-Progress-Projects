typedef struct	s_point
  {
    int           x;
    int           y;
  }               t_point;

void	ft_recursive(char **tab, t_point size, char target, int horizontal, int vertical)
{
	if (horizontal < 0 || vertical < 0 || horizontal >= size.y || vertical >= size.x)
		return;
	if (tab[horizontal][vertical] == 'F' || tab[horizontal][vertical] != target)
		return;
	tab[horizontal][vertical] = 'F';
	ft_recursive(tab, size, target, horizontal - 1, vertical);
	ft_recursive(tab, size, target, horizontal + 1, vertical);
	ft_recursive(tab, size, target, horizontal, vertical + 1);
	ft_recursive(tab, size, target, horizontal, vertical - 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target = tab[begin.y][begin.x];
	ft_recursive(tab, size, target, begin.y, begin.x);
}

#include <stdio.h>

int	main(void)
{
	t_point	size = {8, 6};
	t_point	begin = {7, 5};
	char	zone[6][8] = {
		"11111111",
		"10000101",
		"10001001",
		"10010001",
		"10100001",
		"11111111"
		};
	char	**tab = NULL;
	for (int i = 0; i < size.y; i++)
	{
		for (int j = 0; j < size.x; j++)
			tab[i][j] = zone[i][j];
	}
	for (int i = 0; i < size.y; i++)
		printf("%s", tab[i]);
	flood_fill(tab, size, begin);
	for (int i = 0; i < size.y; i++)
		printf("%s", tab[i]);
	return (0);
}
