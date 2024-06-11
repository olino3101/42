NAME = philosopher
CC = gcc
SRCS = main.c verif.c init.c free.c philo_utils.c verif_utils.c
CFLAGS = -fsanitize="thread" -Wall -Wextra -Werror -g -O2
OBJS = $(SRCS:.c=.o)
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -pthread $(CFLAGS) $(OBJS) -g -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
fclean:
	@rm -f $(NAME)
	@rm -f $(OBJS)
re: fclean all