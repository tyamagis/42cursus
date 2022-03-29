NAME	= push_swap
SRCS	= $(NAME).c \
psw_init_stat.c \
psw_utils.c \
psw_record_utils.c \
psw_stack_utils.c \
psw_operations.c \
psw_set_stack.c \
psw_is_sorted.c \
psw_fool_sort.c \
psw_test_functions.c \
psw_merge_sort.c \

OBJS	= $(SRCS:.c=.o)
#CC=gcc
CFLAGS	=-Wall -Wextra -Werror
#LDFLAGS	=$(CFLAGS)

#CHK_LEAK_CC	= clang
#CHK_LEAK_FLAG	= -Wall -Wextra -Werror -g -fsanitize=leaks

TESTER		= psw_tester
TST_SRCS	= psw_tester.c
TST_OBJS	= $(TST_SRCS:.c=.o)

.PHONY:all re clean fclean test

all: $(NAME)

$(NAME): $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: re $(TESTER)

$(TESTER): $(TST_OBJS)
