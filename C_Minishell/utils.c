/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:05:22 by gtretiak          #+#    #+#             */
/*   Updated: 2025/04/26 13:08:32 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handle_zero(t_mini *ms)
{
	free(ms->input);
	free_tokens(ms->token);
	printf("minishell: erro de sintaxe\n");
	exit(EXIT_FAILURE);
}
