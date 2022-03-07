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
	psw_set_stack.c \
	psw_is_sorted.c \

OBJS	:= $(SRCS:.c=.o)

.PHONY: $(NAME) all re clean fclean test

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

test: re
	./test_psw_arguments.sh
