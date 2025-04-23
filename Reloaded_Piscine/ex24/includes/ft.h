/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:00:50 by gtretiak          #+#    #+#             */
/*   Updated: 2024/10/17 18:55:48 by gtretiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

PRE_SRCS = ./srcs/
PRE_HEAD = ./includes/
SRCS = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
OBJECTS = $(SRCS:.c=.o)
HEAD = ft.h
SRC = $(addprefix $(PRE_SRCS), $(SRCS))
HEADER = $(addprefix $(PRE_HEAD), $(HEAD))
CC = cc -Wall -Wextra -Werror
NAME = libft.a
