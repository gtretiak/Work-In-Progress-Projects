#include <stdio.h>

int	ft_is_even_divisable(int w)
{
	int	n;

	n = 2;
	while (n < w)
	{
		if ((w - n) % 2 == 0)
			return (1);
		n += 2;
	}
	return (0);
}

int	main(void)
{
	int	w;
	scanf("%d", &w);
	if (ft_is_even_divisable(w))
		printf("YES");
	else
		printf("NO");
}
