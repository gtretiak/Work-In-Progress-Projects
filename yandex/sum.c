#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
/*
int	main(void)
{
	int	x;
	int	y;
	scanf("%d %d", &x, &y);
	printf("%d", x + y);
}*/

int	ft_atoi(char *s, int i)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (s[i] && s[i] != ' ' && s[i] != '\n')
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	return (res * sign);
}

int	main(void)
{
	int	x;
	int	y;
	char	*buf;
	int	outfile;
	int	infile;
	int	i;

	i = 0;	
	buf = calloc(sizeof(char), 22);
	if (!buf)
		exit(1);
	infile = open("input.txt", O_RDONLY);
	if (infile == -1)
	{
		free(buf);
		exit(1);
	}
	dup2(infile, 0);
	close(infile);
	fgets(buf, 21, stdin); // "-1245 5479"
	while (buf[i] && buf[i] != ' ')
		i++;
	x = ft_atoi(buf, 0);
	y = ft_atoi(buf, i + 1); 
	outfile = open("output.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (outfile == -1)
	{
		free(buf);
		exit(1);
	}
	dup2(outfile, 1);
	close(outfile);
	printf("%d", x + y);
	free(buf);
	exit(0);
}
