#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_check_flat(char **grid, int yi, int xi, int height, int width)
{
	int	lights;
	int	x;
	int	y;

	lights = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		if (grid[y + yi] == NULL)
			continue ;
		while (x < width)
		{
			if (x + xi >= ft_strlen(grid[y + yi]))
				break ;
			if (grid[y + yi][x + xi] == 'X')
				lights++;
			x++;
		}
		y++;
	}
	if (lights >= (height * width + 1) / 2)
		return (1);
	else
		return (0);
}

void	ft_free_grid(char **grid, int colomns)
{
	int	i;

	i = 0;
	while (i < colomns)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	main(void)
{
	int	i;
	int	count;
	char	**grid;
	int	story;
	int	flats;
	int	height;
	int	width;
	int	yi;
	int	xi;

	count = 0;
	scanf("%d %d %d %d", &story, &flats, &height, &width);
	getchar();
	if (story < 1 || flats < 1 || height < 1 || width < 1 || width > 50)
		exit(1);
	grid = malloc(sizeof(char *) * story * height);
	if (!grid)
		exit(1);
	i = 0;
	while (i < story * height)
	{
		grid[i] = malloc(sizeof(char) * flats * width + 1);
		if (!grid[i])
		{
			ft_free_grid(grid, i);
			exit(1);
		}
		fgets(grid[i], flats * width + 1, stdin);
		getchar();
		i++;
	}
	yi = 0;
	while (yi < story)
	{
		xi = 0;
		while (xi < flats)
		{
			count += ft_check_flat(grid, yi * height, xi * width, height, width);
			xi++;
		}
		yi++;
	}
	printf("%d", count);
	ft_free_grid(grid, story * height);
	exit(0);
}
