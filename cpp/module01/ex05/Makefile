CXX = c++
<<<<<<< HEAD
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = Harl.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Harl
.PHONY: all clean re fclean bonus

all: $(NAME)


=======
FLAGS = -Wall -Wextra -Werror
SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Harl
.PHONY: all clean re fclean

all: $(NAME)

>>>>>>> 6964f94d58263b4200d518278a68f79af47ea6f0
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

%.o: %.cpp
		$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CXX) $(OBJ) -o $(NAME)