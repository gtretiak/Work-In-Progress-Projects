#include "list.h"
#include <stdio.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	tmp;
	t_list	*curr;
	t_list	*last;

	if (!lst || !lst->next)
		return (lst);
	last = NULL;
	while (lst->next != last)
	{
		curr = lst;
		while (curr->next != last)
		{
			if (!cmp(curr->data, curr->next->data))
			{
				tmp = curr->data;
				curr->data = curr->next->data;
				curr->next->data = tmp;
			}
			curr = curr->next;
		}
		last = curr;
	}
	return (lst);
}
/*
int	ascending(int a, int b)
{
	return (a <= b);
}

int	main(void)
{
	t_list new;
	t_list first;
	t_list second;
	t_list *sorted;

	new.data = 15;
	new.next = &first;
	first.data = 42;
	first.next = &second;
	second.data = 3;
	second.next = NULL;
	printf("%d\n%d\n%d\n\n\n", new.data, first.data, second.data);
	sorted = sort_list(&new, ascending);
	printf("%d\n%d\n%d\n", sorted->data, sorted->next->data, sorted->next->next->data);
}*/
