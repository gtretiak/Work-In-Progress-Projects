/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:27:44 by gtretiak          #+#    #+#             */
/*   Updated: 2025/05/14 13:28:12 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_mini *ms)
{
	if (ms->pipe != 0)
		ms->exit_status = exec_pipe(ms);
	else
		ft_exec_token_list(ms);
}
