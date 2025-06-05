#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct ListNode
{
	int	val;
	struct ListNode	*next;
}	ListNode;

struct ListNode	*ft_find_last(struct ListNode *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_finish_him(struct ListNode *list, struct ListNode *final)
{
	struct ListNode	*node;
	struct ListNode	*last;

	last = ft_find_last(final);
	if (!last)
		return ;
	while (list)
	{
		node = malloc(sizeof(struct ListNode));
		node->val = list->val;
		node->next = NULL;
		last->next = node;
		last = node;
		list = list->next;
	}
}

struct ListNode	*mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
	struct ListNode	*final;
	struct ListNode	*node;
	struct ListNode	*last;
	
	final = NULL;
	if (!list1 && list2)
		return (list2);
	if (!list2 && list1)
		return (list1);
	if (!list1 && !list2)
		return (final);
	while (list1 && list2)
	{
		node = malloc(sizeof(struct ListNode));
		node->next = NULL;
		if (list1->val <= list2->val)
		{
			node->val = list1->val;
			list1 = list1->next;
		}
		else
		{
			node->val = list2->val;
			list2 = list2->next;
		}
		if (!final)
			final = node;
		else
		{
			last = ft_find_last(final);
			last->next = node;
		}
	}
	if (list1)
		ft_finish_him(list1, final);
	else if (list2)
		ft_finish_him(list2, final);
	return (final);
}

void	ft_append_node(struct ListNode **list, int n)
{
	struct ListNode	*last;
	struct ListNode	*node;
	
	if (!list)
		return ;
	node = malloc(sizeof(struct ListNode));
	node->next = NULL;
	node->val = n;
	if (!(*list))
		*list = node;
	else
	{
		last = ft_find_last(*list);
		last->next = node;
	}
}

void	ft_iterate_str(struct ListNode **list, char *s)
{
	int	i;
	int	n;
	bool	digits;

	i = 0;
	digits = false;
	while (s[i] && s[i] != '\n')
	{
		while (s[i] && !(s[i] >= '0' && s[i] <= '9'))
			i++;
		if (s[i] && s[i] != '\n')
		{
			n = 0;
			digits = true;
		}
		else
			return ;
		while (s[i] && s[i] >= '0' && s[i] <= '9')
		{
			n *= 10;
			n += s[i] - '0';
			i++;
		}
		if (digits)
			ft_append_node(list, n);
	}
}

void	ft_print_final(struct ListNode *final)
{
	write(1, "[", 1);
	while (final)
	{
		if (final->next)
			printf("%d,", final->val);
		else
			printf("%d", final->val);
		final = final->next;
	}
	printf("]");
}

void	ft_free_list(struct ListNode **list)
{
	struct ListNode	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

int	main(void)
{
	char	*s;
	ListNode	*list1;
	ListNode	*list2;
	ListNode	*final;

	list1 = NULL;
	list2 = NULL;
	final = NULL;
	s = calloc(10000, 1);
	fgets(s, 10000, stdin);
	ft_iterate_str(&list1, s);
	free(s);
	s = NULL;
	s = calloc(10000, 1);
	fgets(s, 10000, stdin);
	ft_iterate_str(&list2, s);
	free(s);
	final = mergeTwoLists(list1, list2);
	ft_print_final(final);
	if(list1 && list2)
	{
		ft_free_list(&final);
		ft_free_list(&list1);
		ft_free_list(&list2);
	}
	else if (!list1 && list2)
		ft_free_list(&list2);
	else if (!list2 && list1)
		ft_free_list(&list1);
	exit(EXIT_SUCCESS);
}
