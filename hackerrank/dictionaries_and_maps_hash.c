#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define SIZE 1000003

typedef struct s_phone_book
{
	char	*name;
	int	num;
	struct s_phone_book	*next;
}	t_phone_book;

t_phone_book	*ft_find_last(t_phone_book *pb)
{
	if (!pb)
		return (NULL);
	while (pb->next)
		pb = pb->next;
	return (pb);
}

char	*ft_substr(char *s, unsigned long start, int size)
{
	int	i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	if (start > strlen(s))
		return (strdup(""));
	if (start + size > strlen(s))
		size = strlen(s + start);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (size > i)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

unsigned int	hash_function(const char *s)
{
	unsigned long	res;

	res = 5381;
	while (*s)
	{
		res = ((res << 5) + res) + *s;
		s++;
	}
	return (res % SIZE);
}

void	ft_fill_stack(t_phone_book *pb[], char **s, int n)
{
	int	i;
	int	j;
	unsigned int	index;
	t_phone_book	*node;

	i = 0;
	while (i < n)
	{
		j = 0;
		node = malloc(sizeof(t_phone_book));
		node->name = NULL;
		node->next = NULL;
		while (s[i][j] && isalpha(s[i][j]))
			j++;
		node->name = ft_substr(s[i], 0, j);
		j++;
		node->num = atoi(s[i] + j);
		index = hash_function(node->name);
		node->next = pb[index];
		pb[index] = node;
/*		if (!(*pb))
			*pb = node;
		else
		{
			last = ft_find_last(*pb);
			last->next = node;
		}*/
		i++;
	}
}

void	ft_free_arr(char **s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_free_stack(t_phone_book *stack[])
{
	t_phone_book	*tmp;
	t_phone_book	*node;

	for (int i = 0; i < SIZE; i++)
	{
		node = stack[i];
		while (node)
		{
//			if (stack->name)
//				free(stack->name);
			tmp = node->next;
			free(node->name);
			free(node);
			node = tmp;
		}
		stack[i] = NULL;
	}
}

t_phone_book	*ft_find_node(char *s, t_phone_book *pb[])
{
	unsigned int	index;
	t_phone_book	*node;
	size_t	len;

	if (!s)
		return (NULL);
	len = strlen(s);
	if (s[len - 1] == '\n')
		s[len - 1] = '\0';
	index = hash_function(s);
	node = pb[index];
	while (node)
	{
		if (!strcmp(s, node->name))
			return (node);
		node = node->next;
	}
	return (NULL);
}

int	main(void)
{
	int	n;
	int	i;
	char	str[40];
	char	**s;
	t_phone_book	*pb[SIZE] = {NULL};
	t_phone_book	*test;

	scanf("%d", &n);
	getchar();
	i = 0;
	s = malloc(sizeof(char *) * n);
	while (i < n)
	{
		s[i] = calloc(sizeof(char), 40);
		fgets(s[i], 40, stdin);
		i++;
	}
	ft_fill_stack(pb, s, n);
	ft_free_arr(s, n);
	while (1)
	{
		if (!fgets(str, sizeof(str), stdin))
			break ;
		test = ft_find_node(str, pb);
		if (test)
			printf("%s=%d\n", test->name, test->num);
		else
			printf("Not found\n");
	}
	ft_free_stack(pb);
	return (0);
}
