# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onault <onault@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 13:36:58 by onault            #+#    #+#              #
#    Updated: 2024/06/30 16:05:41 by onault           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Zombie
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