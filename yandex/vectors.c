#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	size;
	int	i;
	int	*q;
	unsigned char	*c;
	long long	*d;
	int	min;
	int	max;
	long long	res;

	scanf("%d", &size);
	getchar();
	q = malloc(sizeof(int) * size);
	if (!q)
		exit(1);
	i = 0;
	while (i < size)
	{
		scanf("%d", &q[i]);
		i++;
	}
	getchar();
	c = malloc(sizeof(unsigned char) * size);
	if (!c)
	{
		free(q);
		exit(1);
	}
	i = 0;
	while (i < size)
		scanf("%hhu", &c[i++]);
	getchar();
	scanf("%d %d", &min, &max);
	getchar();
	d = malloc(sizeof(long long) * size);
	if (!d)
	{
		free(q);
		free(c);
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		if (min == max)
			d[i] = min;
		else
			d[i] = min + (c[i] * (long long)(max - min) + 127) / 255;
		i++;
	}
	i = 0;
	res = 0;
	while (i < size)
	{
		res += (long long)q[i] * d[i];
		i++;
	}
	printf("%lld", res);
	free(q);
	free(c);
	free(d);
	exit(0);
}
