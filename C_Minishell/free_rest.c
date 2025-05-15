/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:53:07 by gtretiak          #+#    #+#             */
/*   Updated: 2025/05/14 12:53:37 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_curr_args_file(t_token *current)
{
	int	i;

	i = 0;
	while (current->args_file[i])
	{
		free(current->args_file[i]);
		current->args_file[i] = NULL;
		i++;
	}
	free(current->args_file);
	current->args_file = NULL;
}

static void	ft_free_curr_args(t_token *current)
{
	int	i;

	i = 0;
	if (current->args)
	{
		while (current->args[i])
		{
			free(current->args[i]);
			current->args[i] = NULL;
			i++;
		}
		free(current->args);
		current->args = NULL;
	}
	if (current->args_file)
		ft_free_curr_args_file(current);
}

void	ft_free_minishell(t_mini *ms, int code)
{
	t_token	*current;
	t_token	*next;

	if (!ms || !ms->state)
		return ;
	current = ms->state->curr;
	while (current)
	{
		next = current->next;
		ft_free_curr_args(current);
		if (code == 100)
			current = next;
		else
			break ;
	}
}

void	free_env_list(t_env *head)
{
	t_env	*current;
	t_env	*next;

	current = head;
	while (current)
	{
		next = current->next;
		if (current->content)
			free(current->content);
		if (current->var)
			free(current->var);
		free(current);
		current = next;
	}
}
