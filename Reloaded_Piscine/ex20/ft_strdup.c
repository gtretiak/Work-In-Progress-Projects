/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:12:54 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/15 14:51:06 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	short	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	short	i;
	short	l;
	char	*dup;

	i = 0;
	l = ft_strlen(src);
	dup = malloc(sizeof(char) * (l + 1));
	if (dup == NULL)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(void)
{
	char	*src = "baobab";
	char	*mine = NULL;
	char	*theirs = NULL;
	printf("src:%s:, address:%p:\n", src, src);
	mine = ft_strdup(src);
	theirs = strdup(src);
	printf("strdup:%s:, address:%p:\n", mine, mine);
	printf("original:%s:, address:%p:\n", theirs, theirs);
}*/
