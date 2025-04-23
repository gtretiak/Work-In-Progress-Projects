#include <unistd.h>
#include <stdlib.h>

int	ft_countn(long nb)
{
	int	i;
	
	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_special(int n)
{
	char	*s;
	if (n == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	else
		return (NULL);
}

char	*ft_itoa(int n)
{
	short	l;
	char	*s;
	
	if (n == 0)
		return (ft_special(n));
	else
	{
		l = ft_countn(n);
		s = malloc(sizeof(char) * l + 1);
		if (!s)
			return (NULL);
                s[l] = '\0';
		while (n)
		{
			s[--l] = n % 10 + '0';
			n /= 10;
		}
		return (s);
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_check_flat(char **av, int yi, int xi, int height, int width)
{
	int	lights;
	int	x;
	int	y;

	lights = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		if (av[y + yi] == NULL)
			continue ;
		while (x < width)
		{
			if (x + xi >= ft_strlen(av[y + yi]))
				break ;
			if (av[y + yi][x + xi] == 'X')
				lights++;
			x++;
		}
		y++;
	}
	if (lights >= height * width / 2)
		return (1);
	else
		return (0);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	main(int argc, char **av)
{
	int	count;
	char	*s;
	int	story;
	int	flats;
	int	height;
	int	width;
	int	yi;
	int	xi;

	if (argc < 5)
		exit(1);
	count = 0;
	story = atoi(av[1]);
	flats = atoi(av[2]);
	height = atoi(av[3]);
	width = atoi(av[4]);
	if (story < 1 || flats < 1 || height < 1 || width < 1 || width > 50)
		exit(1);
	yi = 5;
	while (yi < story * height + 5)
	{
		xi = 0;
		while (xi < flats * width)
		{
			count += ft_check_flat(av, yi, xi, height, width);
			xi += width;
		}
		yi += height;
	}
	s = ft_itoa(count);
	if (!s)
		exit(1);
	ft_putstr(s);
	free(s);
	exit(0);
}
