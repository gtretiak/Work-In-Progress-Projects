/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:49:22 by gtretiak          #+#    #+#             */
/*   Updated: 2025/05/14 14:10:39 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

static int	ft_execute_builtin(t_token *cmd_token, t_mini *ms, int fd)
{
	int	original_stdin;
	int	status;

	original_stdin = dup(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	close(fd);
	status = exec_builtin(cmd_token, ms);
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
	return (status);
}

static int	ft_execute_external(t_token *cmd_token, t_mini *ms, int fd)
{
	int	original_stdin;
	int	status;

	original_stdin = dup(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	close(fd);
	status = execute_command(cmd_token, ms);
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
	return (status);
}

static int	ft_heredoc_default(int fd)
{
	int		original_stdin;
	int		bytes_read;
	char	buffer[4096];

	original_stdin = dup(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	close(fd);
	while (1)
	{
		bytes_read = read(STDIN_FILENO, buffer, 4095);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		ft_putstr_fd(buffer, STDOUT_FILENO);
	}
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
	return (0);
}

static t_token	*ft_find_cmd_token(const t_token *token)
{
	t_token	*current;

	current = token->prev;
	while (current && current->type != CMD_EXEC && current->type != CMD_BUILDIN)
		current = current->prev;
	return (current);
}

int	exec_heredoc(t_token *token, t_mini *ms)
{
	int		fd[2];
	t_token	*next;
	t_token	*cmd_token;
	int		heredoc_status;

	heredoc_status = ft_validate_token(token, &next);
	if (heredoc_status != 0)
		return (heredoc_status);
	cmd_token = ft_find_cmd_token(token);
	if (!cmd_token || !cmd_token->cmd)
	{
		ft_putstr_fd("minishell: no command found\n", 2);
		return (ft_heredoc_default(fd[0]));
	}
	heredoc_status = ft_handle_heredoc_input(next, fd);
	if (heredoc_status != 0)
		return (heredoc_status);
	if (cmd_token->type == CMD_EXEC)
		return (ft_execute_external(cmd_token, ms, fd[0]));
	if (cmd_token->type == CMD_BUILDIN)
		return (ft_execute_builtin(cmd_token, ms, fd[0]));
	ft_putstr_fd("minishell: invalid command type\n", 2);
	return (ft_heredoc_default(fd[0]));
}
