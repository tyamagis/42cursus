CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap
SRCS		= \
	$(NAME).c \
	psw_is_sorted.c \
	psw_radix_sort.c \
	psw_selection_sort.c \
	psw_sort_utils.c \
	psw_init_stat.c \
	psw_operations.c \
	psw_record_utils.c \
	psw_set_stack.c \
	psw_utils.c \
	psw_radix2_sort.c

OBJS		= $(SRCS:.c=.o)

.PHONY: all re clean fclean

$(NAME): $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
