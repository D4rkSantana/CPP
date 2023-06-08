# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 20:52:30 by esilva-s          #+#    #+#              #
#    Updated: 2023/06/08 13:13:45 by esilva-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

INCLUDES = -I PhoneBook.hpp Contact.hpp
SRC = main.cpp PhoneBook.cpp Contact.cpp PhoneBook_tools.cpp 
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