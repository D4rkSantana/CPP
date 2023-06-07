# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 20:10:51 by esilva-s          #+#    #+#              #
#    Updated: 2023/06/06 20:54:17 by esilva-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unnecessary_violence
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

INCLUDES = -I Weapon.hpp HumanA.hpp HumanB.hpp
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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