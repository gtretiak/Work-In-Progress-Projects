#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	long long	code;
	char	*str;
	int	words;
	char	*arr;
	int	i;

	scanf("%s", &code);
	getchar();
	scanf("%d", &words);
	getchar();
	arr = malloc(sizeof(257) * words + 1);
	if (!arr)
		exit(1);
	i = 0;
	while (i < words)
	{
		scanf("%s", &arr[i]);
		getchar();
		i++;
	}
	arr[i] = NULL;
	getchar();
	str = ft_ltoa(code);//TODO

	printf("%s", res);
	free(arr);
	exit(0);
}
