# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 20:04:36 by esilva-s          #+#    #+#              #
#    Updated: 2023/06/08 13:13:17 by esilva-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

INCLUDES = -I Zombie.hpp
SRC = main.cpp Zombie.cpp zombieHorde.cpp
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