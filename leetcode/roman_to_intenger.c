#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	ft_return_subtraction(char c1, char c2)
{
	if (c1 == 'I' && c2 == 'V')
		return (4);
	else if (c1 == 'I' && c2 == 'X')
		return (9);
	else if (c1 == 'X' && c2 == 'L')
		return (40);
	else if (c1 == 'X' && c2 == 'C')
		return (90);
	else if (c1 == 'C' && c2 == 'D')
		return (400);
	else if (c1 == 'C' && c2 == 'M')
		return (900);
	printf("Weird error has happened\n");
	exit(EXIT_FAILURE);
}

int	ft_return_converted(char c)
{
	if (c == 'I')
		return (1);
	else if (c == 'V')
		return (5);
	else if (c == 'X')
		return (10);
	else if (c == 'L')
		return (50);
	else if (c == 'C')
		return (100);
	else if (c == 'D')
		return (500);
	else if (c == 'M')
		return (1000);
	else
	{
		printf("Invalid Roman letter is given\n");
		exit(EXIT_FAILURE);
	}
}

int	romanToInt(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while(s[i] && s[i] != '\n')
	{
		if (s[i + 1] && ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
			|| (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
			|| (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))))
		{
			res += ft_return_subtraction(s[i], s[i + 1]);
			i++;
		}
		else
			res += ft_return_converted(s[i]);		
		if (s[i] || s[i] == '\n')
			i++;
	}
	return (res);
}

int	main(void)
{
	int	size = 1024;
	char	s[size];
	printf("Insert any Roman numeral\n"
		"They are represented by letters I, V, X, L, C, D, and M\n"
		"Subtraction rules:\n"
		"I can be placed before V or X (-1)\n"
		"X can be placed before L or C (-10)\n"
		"C can be placed before D or M (-100)\n");
	fgets(s, size, stdin);
	printf("%d", romanToInt(s));
	exit(EXIT_SUCCESS);
}
