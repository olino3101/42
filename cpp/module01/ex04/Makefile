CXX = c++
FLAGS = -Wall -Wextra -Werror
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = replace
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