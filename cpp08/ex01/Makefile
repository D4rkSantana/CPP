# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 21:13:33 by esilva-s          #+#    #+#              #
#    Updated: 2023/09/28 23:37:05 by esilva-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

INCLUDES = Span.hpp
SRC = main.cpp Span.cpp
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