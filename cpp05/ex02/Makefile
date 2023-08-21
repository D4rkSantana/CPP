# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 21:13:33 by esilva-s          #+#    #+#              #
#    Updated: 2023/08/21 23:56:42 by esilva-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

INCLUDES = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBG = $(SRC:.cpp=.o) 


all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(FLAGS) $(OBG) -o $(NAME)


$(OBG): $(SRC) $(INCLUDES)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all