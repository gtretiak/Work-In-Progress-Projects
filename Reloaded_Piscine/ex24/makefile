# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 17:01:57 by gtretiak          #+#    #+#              #
#    Updated: 2024/10/17 19:03:07 by gtretiak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re make_lib

all: make_lib

make_lib: $(OBJECTS) 
	$(CC) -I$(HEADER) -c $(SRC)
	ar -rc $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $?
clean:
	rm -f$(OBJECTS)
fclean:
	clean
	rm -f$(NAME)
re:
	fclean
	all
