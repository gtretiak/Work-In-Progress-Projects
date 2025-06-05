#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_debt
{
	int	debt;
	struct s_debt	*next;
}	t_debt;

int	ft_define_debt(char c)
{
	if (c == '(')
	       return (3);
	else if (c == '[')
		return (5);
	else if (c == '{')
		return (7);
	else if (c == ')')
		return (-3);
	else if (c == ']')
		return (-5);
	else if (c == '}')
		return (-7);
	return (0);
}

bool	isValid(char* s)
{
	int	res;
	t_debt	*node;
	t_debt	*tmp;
	t_debt	*new;

	res = 0;
	node = NULL;
	while (*s)
	{
		res = ft_define_debt(*s);
		if (res > 0)
		{
			new = malloc(sizeof(t_debt));
			if (!new)
			{
				printf("Malloc error\n");
				exit(EXIT_FAILURE);
			}
			new->debt = res;
			new->next = node;
			node = new;
		}
		else if (res < 0)
		{	
			if (!node)
				return (false);
			if (node->debt != -res)
			{
				while (node)
				{
					tmp = node;
					node = node->next;
					free(tmp);
				}
				return (false);
			}
			tmp = node;
			node = node->next;
			free(tmp);
		}
		s++;
	}
	if (node == NULL)
		res = 0;
	else
		res = 1;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	if (res == 0)
		return (true);
	else
		return (false);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		printf("Too few args\n");
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (isValid(argv[i]))
			printf("true");
		else
			printf("false");
		i++;
	}
	exit(EXIT_SUCCESS);
}
