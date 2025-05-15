/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:17:06 by gtretiak          #+#    #+#             */
/*   Updated: 2025/05/14 12:25:41 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_parser(t_parser *state)
{
	state->curr = NULL;
	state->prev = NULL;
	state->last_cmd = NULL;
	state->cmd_seen = 0;
}

int	main(int argc, char *argv[], char **envp)
{
	t_mini		ms;
	t_parser	state;

	(void)(argc);
	(void)(argv);
	ms = init(envp);
	ft_init_parser(&state);
	ms.state = &state;
	while (1)
	{
		ms.input = get_input(&ms, ms.prompt);
		ms.token = lexer(ms.input);
		if (ms.token)
		{
			if (!parser(&state, &ms))
				ft_handle_zero(&ms);
			exec(&ms);
			free_tokens(ms.token);
		}
		ft_update_ms(&ms);
	}
	free_env_list(ms.export);
	ft_free_minishell(&ms, 100);
	exit(EXIT_SUCCESS);
}
