# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 19:50:47 by esilva-s          #+#    #+#              #
#    Updated: 2023/06/06 19:51:04 by esilva-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

INCLUDES = -I Zombie.hpp
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBG = $(SRC:.cpp=.o)

all: $(OBG)
	$(CC) $(FLAGS) $(OBG) -o $(NAME)

$(OBG): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all