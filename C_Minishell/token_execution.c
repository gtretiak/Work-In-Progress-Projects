/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:27:18 by gtretiak          #+#    #+#             */
/*   Updated: 2025/05/14 13:27:29 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_token(t_token *current, t_token *prev, t_mini *ms)
{
	if (current->type == CMD_BUILDIN)
		ms->exit_status = exec_builtin(current, ms);
	else if (current->type == CMD_EXPR)
		process_expr_command(current, ms);
	else if (current->type == CMD_EXEC)
		ms->exit_status = execute_command(current, ms);
	else if (current->type == CMD_EXIT_STATUS
		&& (!prev || prev->type != CMD_EXPR))
	{
		printf("command not found: %d\n", ms->exit_status);
		ms->exit_status = 127;
	}
	else if ((!prev || prev->type != CMD_EXPR) && current->type != CMD_PLUS)
	{
		ms->exit_status = 127;
		return (1);
	}
	return (0);
}

static void	process_special_token(t_token *special_token, t_mini *ms)
{
	if (special_token->type == CMD_REDIRECT_OUT)
		ms->exit_status = exec_redirect(special_token, ms);
	else if (special_token->type == CMD_REDIRECT_IN)
		ms->exit_status = exec_redirect(special_token, ms);
	else if (special_token->type == CMD_HEREDOC)
		ms->exit_status = exec_heredoc(special_token, ms);
}

static t_token	*find_special_token(t_token *current)
{
	t_token	*temp;
	t_token	*special_token;

	special_token = NULL;
	temp = current->next;
	while (temp && temp->type != CMD_PIPE
		&& temp->type != CMD_BUILDIN && temp->type != CMD_EXEC)
	{
		if (temp->type == CMD_REDIRECT_OUT || temp->type == CMD_REDIRECT_IN
			|| temp->type == CMD_HEREDOC)
		{
			special_token = temp;
			break ;
		}
		temp = temp->next;
	}
	return (special_token);
}

static int	process_curr_token(t_token **curr, t_token **prev, t_mini *ms)
{
	t_token	*special_token;
	t_token	*temp;

	if ((*curr)->type == CMD_BUILDIN || (*curr)->type == CMD_EXEC)
	{
		special_token = find_special_token(*curr);
		if (special_token)
		{
			process_special_token(special_token, ms);
			temp = (*curr)->next;
			while ((*curr) && *curr != temp)
				*curr = (*curr)->next;
			if (*curr)
				*prev = (*curr)->prev;
			else
				*prev = NULL;
			return (1);
		}
	}
	return (0);
}

void	ft_exec_token_list(t_mini *ms)
{
	t_token	*current;
	t_token	*prev;

	current = ms->token;
	prev = NULL;
	while (current)
	{
		if (process_curr_token(&current, &prev, ms))
			continue ;
		if (ft_handle_token(current, prev, ms))
			return ;
		prev = current;
		current = current->next;
	}
}
