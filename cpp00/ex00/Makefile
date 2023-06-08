# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 19:46:53 by esilva-s          #+#    #+#              #
#    Updated: 2023/06/08 13:13:54 by esilva-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = megaphone.cpp
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

re:	fclean	all
	