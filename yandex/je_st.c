#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*j;
	char	*s;
	int	res;
	int	i;

	i = 0;	
	j = calloc(sizeof(char), 101);
	if (!j)
		exit(1);
	fgets(j, 101, stdin);
	//getchar();
	s = calloc(sizeof(char), 101);
	if (!s)
	{
		free(j);
		exit(1);
	}
	fgets(s, 101, stdin);
	while (j[i] && j[i] != '\n')
		i++;
	j[i] = '\0';
	i = 0;	
	while (s[i] && s[i] != '\n')
		i++;
	s[i] = '\0';
	i = 0;	
	res = 0;
	while (s[i])
	{
		if (strchr(j, s[i]))
			res++;
		i++;
	}
	printf("%d", res);
	free(j);
	free(s);
	exit(0);
}
