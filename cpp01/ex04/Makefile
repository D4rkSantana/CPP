NAME = replace
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

INCLUDES = -I replace.hpp
SRC = main.cpp replace.cpp replace.hpp
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