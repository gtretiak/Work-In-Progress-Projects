CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./42-libft
LIBS = -lreadline -L./42-libft -lft
NAME = minishell

SRCS = $(wildcard *.c) \
		$(wildcard commands/*.c) \
		$(wildcard commands/heredoc/*.c) \
		$(wildcard commands/heredoc/heredoc_with_pipe/*.c) \
		$(wildcard commands/pipe/*.c) \
		$(wildcard commands/redirect/*.c) \
		$(wildcard commands/builtin/*.c) \
		$(wildcard parsing/*.c) \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./42-libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C ./42-libft
	rm -f $(OBJS)

fclean: clean
	@make fclean -C ./42-libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
