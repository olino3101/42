
CXX = c++
FLAGS = -Wall -Wextra -Werror
SRC = main.cpp PhoneBook.cpp contact.cpp
OBJ = $(SRC:.cpp=.o)
NAME = PhoneBook
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