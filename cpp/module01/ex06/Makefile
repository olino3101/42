CXX = c++
<<<<<<< HEAD
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = Harl.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Harlfilter
.PHONY: all clean re fclean bonus
=======
FLAGS = -Wall -Wextra -Werror
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Harl
.PHONY: all clean re fclean
>>>>>>> 6964f94d58263b4200d518278a68f79af47ea6f0

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