# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 20:07:51 by esilva-s          #+#    #+#              #
#    Updated: 2023/06/08 13:13:09 by esilva-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hi_this_is_brain
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp
OBG = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBG) 
	$(CC) $(FLAGS) $(OBG) -o $(NAME)

$(OBG): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all
