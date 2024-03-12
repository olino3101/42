CC = cc
FLAGS = -Wall -Wextra -Werror
DEPS = libft.h
OBJ = ft_printf.o ft_puts.o ft_putnbr_base.o
NAME = libftprintf.a

.PHONY: all clean re fclean

all: $(NAME)

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)
