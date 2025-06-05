#include <unistd.h>
#include <stdio.h>

void	compare_bits(int x, int y)
{
	printf("%d", x & y);
}

int	main(void)
{
	int	x = 19;
	int	y = 21;
	compare_bits(x, y);
}
