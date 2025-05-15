/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:52:21 by gtretiak          #+#    #+#             */
/*   Updated: 2025/05/14 12:53:01 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_token_args_file(t_token *token)
{
	int	i;

	i = 0;
	while (token->args_file[i])
	{
		free(token->args_file[i]);
		token->args_file[i] = NULL;
		i++;
	}
	free(token->args_file);
	token->args_file = NULL;
}

static void	ft_free_token_args(t_token *token)
{
	int	i;

	i = 0;
	if (token->args)
	{
		while (token->args[i])
		{
			free(token->args[i]);
			token->args[i] = NULL;
			i++;
		}
		free(token->args);
		token->args = NULL;
	}
	if (token->args_file)
		ft_free_token_args_file(token);
}

void	free_tokens(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token->next;
		if (token->cmd)
		{
			free(token->cmd);
			token->cmd = NULL;
		}
		ft_free_token_args(token);
		free(token);
		token = tmp;
	}
}
