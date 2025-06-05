#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_get_answer(int *n)
{
	 *n = (*n / 10) + (*n % 10);
}

int	main(void)
{
	int	num_of_test_cases;
	int	i;
	int	*n;

	scanf("%d", &num_of_test_cases);
	i = 0;
	n = malloc(sizeof(int) * num_of_test_cases);
	while (i < num_of_test_cases)
	{
		scanf("%d", &n[i]);
		ft_get_answer(&n[i]);
		i++;
	}
	i = 0;
	while (i < num_of_test_cases - 1)
	{
		printf("%d\n", n[i]);
		i++;
	}
	printf("%d", n[i]);
	free(n);
}
