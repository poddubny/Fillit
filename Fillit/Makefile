# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoddubn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 04:55:58 by mpoddubn          #+#    #+#              #
#    Updated: 2018/01/24 04:56:07 by mpoddubn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

FLAGS	=	-Wall -Werror -Wextra

CC		=	gcc $(FLAGS)

SRC		=	main.c\
			validation.c\
			figure_cut.c\
			map_creator.c\
			backtrack.c\
			extra.c
			
OBJ	=		$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(SRC) -I fillit.h
	@echo "Compiling" [ $(NAME) ]

%.o: %.c fillit.h
	@$(CC) -c -o $@ $< -I fillit.h
	@echo "Linking" [ $< ]

clean:
	@rm -f $(OBJ)
	@echo "Cleaning .o files"

fclean: clean
	@rm -f $(NAME)
	@echo "Remove" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re