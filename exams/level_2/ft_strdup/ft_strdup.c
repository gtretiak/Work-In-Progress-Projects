#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *src)
{
	if (!src)
		return (NULL);
	char	*res;
	int	i = 0;
	
	while (src[i])
		i++;
	res = malloc(sizeof(char) * i + 1);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return(res);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*dest;
	char	*src = "Hello<";
	printf("SRC:%s\n", src);
	dest = ft_strdup(src);
	printf("NEW:%s\n", dest);
	free(dest);
}*/
