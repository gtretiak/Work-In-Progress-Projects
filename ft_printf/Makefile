# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:46:38 by gtretiak          #+#    #+#              #
#    Updated: 2024/11/22 17:30:00 by gtretiak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_DIR = Libft/
LIBFT = libft.a
SRCS_DIR = Sources/
SRCS = ft_printf.c ft_unitoa.c ft_print_address.c ft_print_hex.c \
       ft_take_address.c ft_check_chars.c ft_check_numbers.c ft_check_else.c
OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
SOURCES = ft_isalpha.c ft_isascii.c ft_isdigit.c ft_strncmp.c ft_strlen.c \
	  ft_isalnum.c ft_isprint.c ft_strchr.c ft_toupper.c ft_tolower.c \
	  ft_strrchr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	  ft_strlcpy.c ft_strlcat.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c
OBJECTS = $(addprefix $(LIBFT_DIR), $(SOURCES:.c=.o))
HEAD = ft_printf.h
HEAD_DIR = Headers/
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT): 
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(OBJECTS)
	ar -rc $(NAME) $^

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c $(HEAD_DIR)$(HEAD)
	cc $(CFLAGS) -I$(HEAD_DIR) -I$(LIBFT_DIR) -c $< -o $@

.PHONY: clean fclean re

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all


