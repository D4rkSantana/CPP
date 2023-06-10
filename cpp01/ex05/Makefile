NAME = harl
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

INCLUDES = Harl.hpp
SRC = main.cpp Harl.cpp
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