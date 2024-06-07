
CXX = g++
FLAGS = -Wall -Wextra -Werror  -std=c++98
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
NAME = megaphone
.PHONY: all clean re fclean bonus

all: $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

%.o: %.c
		$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)