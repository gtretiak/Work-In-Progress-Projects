#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int	ft_define_fine(int *returned, int *expected)
{
	if (returned[2] > expected[2])
	       return (10000);
	else
	{
		if (returned[2] < expected[2])
		       return (0);
		else
		{
			if (returned[1] > expected[1])
				return (500 * (returned[1] - expected[1]));
			else
			{
				if (returned[1] < expected[1])
					return (0);
				else
				{
					if (returned[0] > expected[0])
						return (15 * (returned[0] - expected[0]));
					else
						return (0);
				}
			}
		}
	}
}

int	main(void)
{
	int	book_returned[3];
	int	book_expected[3];
	int	i;

	i = 0;
	while (i < 3)
		scanf("%d", &book_returned[i++]);
	i = 0;
	while (i < 3)
		scanf("%d", &book_expected[i++]);
	printf("%d", ft_define_fine(book_returned, book_expected));
	return (EXIT_SUCCESS);
}
