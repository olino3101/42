CXX = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp convert.cpp
OBJ = $(SRC:.cpp=.o)
NAME = ex00
.PHONY: all clean re fclean

all: $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

%.o: %.cpp
		$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CXX) $(OBJ) -o $(NAME)