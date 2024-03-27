NAME = push_swap
CC = gcc
SRCS = main.c command.c utils.c arg.c more_utils.c five_less.c three_less.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(LIB):
	make -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJS)
re: fclean all