NAME	:= libftprintf.a
CC		:= gcc
FLG		:= -Wall -Wextra -Werror

SRC		:= ft_printf.c ft_printf_func.c
OBJ		:= $(SRC:.c=.o)

.SUFFIXES: .c .o
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $^

.c.o:
	$(CC) $(FLG) -c $<

clean:
	rm -f $(OBJ) $(BOBJ) ft_printf.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
