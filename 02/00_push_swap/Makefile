NAME	:= push_swap
CC		:= gcc
FLAG	:= -Wall -Wextra -Werror

L_CC	:= clang
L_FLAG	:= -Wall -Wextra -Werror -g -fsanitize=leaks

SRCDIR	:= srcs
SRCS	:= \
	push_swap.c \
	psw_init_stat.c \
	psw_utils.c \
	psw_operations.c \

OBJS	:= $(SRCS:.c=.o)

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $^ -o $(NAME)

.c.o:
	$(CC) $(FLAG) -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
