/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:09:30 by gtretiak          #+#    #+#             */
/*   Updated: 2025/05/14 14:10:10 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	ft_handle_heredoc_input(const t_token *next, int fd[2])
{
	char	*line;

	if (!next || !next->cmd)
		return (127);
	if (pipe(fd) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", 2);
		return (1);
	}
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, next->cmd) == 0)
			break ;
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	free(line);
	close(fd[1]);
	return (0);
}

int	ft_validate_token(t_token *token, t_token **next)
{
	if (!token || !token->cmd || ft_strcmp(token->cmd, "<<") != 0)
	{
		ft_putstr_fd("minishell: invalid heredoc token\n", 2);
		return (127);
	}
	*next = token->next;
	if (!*next || !(*next)->cmd)
	{
		ft_putstr_fd("minishell: no delimiter provided\n", 2);
		return (127);
	}
	return (0);
}
