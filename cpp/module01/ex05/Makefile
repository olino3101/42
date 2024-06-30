CXX = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = Harl.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Harl
.PHONY: all clean re fclean bonus

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