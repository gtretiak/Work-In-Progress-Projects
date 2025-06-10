#include <stdio.h>
#include <string.h>

int	max(int *tab, unsigned int len)
{
	int	l = len;
	int	big;
	int	i = 0;
	int	j = 1;
	if (tab == NULL)
		return (0);
	big = tab[i];
	while (i < (l - 1))
	{
		while (((i + j) < l) && (tab[i] > tab[i + j]))
			j++;
		if ((i + j) == l)
			return (big);
		else
			big = tab[i + j];
		i++;
	}
	return (big);
}
/*
int	main(void)
{
	int	arr[4] = {9, 6, 65, 2};
	unsigned int	len = 4;
	printf("%d", max(arr, len));
}*/
