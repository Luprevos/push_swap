# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luprevos <luprevos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 14:32:13 by luprevos          #+#    #+#              #
#    Updated: 2025/02/18 18:47:31 by luprevos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap

SRC = 	1stpart.c\
		zcaca44.c\
		2ndpart.c\
		3rdpart.c\
		algo.c\
		algo2nd.c\
		error.c\
		main.c\
		mediane.c\
		parsing.c\
		sort.c\
		sort2nd.c\
		split.c\
		utils.c\
		utils2nd.c


OBJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean