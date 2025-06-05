#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char	*ft_is_prime(int n)
{
	if (n <= 1)
		return ("Not prime");
	if (n == 2 || n == 3)
		return ("Prime");
	if (!(n % 2)) // checking all even numbers
		return ("Not prime");
	for (int i = 3; i * i <= n; i += 2) // checking the sequence of odd numbers
	{
		if (!(n % i))
			return ("Not prime");
	}
	return ("Prime");
}

int	main(void)
{
	int	test_cases;
	int	i;
	int	*nums;

	scanf("%d", &test_cases);
	i = 0;
	nums = malloc(sizeof(int) * test_cases);
	while (i < test_cases)
		scanf("%d", &nums[i++]);
	i = 0;
	while (i < test_cases)
		printf("%s\n", ft_is_prime(nums[i++]));
	free(nums);
	return (0);
}
