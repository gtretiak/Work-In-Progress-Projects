#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_get_abbv(char *s)
{
	int	i;
	int	j;
	char	*res;

	i = 1;
	j = 1;
	res = calloc(sizeof(char), 4);
	if (!res)
	{
		printf("Malloc error\n");
		exit(EXIT_FAILURE);
	}
	res[0] = s[0];
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != ' ' && s[i - 1] == ' ')
		{
			res[j] = s[i];
			j++;
		}
		i++;
	}
	res[3] = '\0';
	return (res);
}

int	main(void)
{
	int	n;
	int	i;
	char	*tmp;
	char	s[100][33];

	i = 0;
	scanf("%d", &n);
	getchar();
	while (i < n)
	{
		fgets(s[i], 33, stdin);
		tmp = ft_get_abbv(s[i]);
		strcpy(s[i], tmp);
		free(tmp);
		i++;
	}
	i = 0;
	while (i < n - 1)
		printf("%s\n", s[i++]);
	printf("%s", s[i]);
	exit(EXIT_SUCCESS);
}
