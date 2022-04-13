NAME		= push_swap
CC			= cc
INCLUDE		= -I./includes
CFLAGS		= -Wall -Wextra -Werror $(INCLUDE)

SRCDIR		= ./src/
OBJDIR		= ./obj/
VPATH		= $(SRCDIR)utils $(SRCDIR)sorts $(OBJDIR)

SRC_MAIN	= $(NAME).c

SRC_UTILS	= \
	psw_init_stat.c \
	psw_set_stack.c \
	psw_operations.c \
	psw_is_sorted.c \
	psw_utils.c \
	psw_record_utils.c \
	psw_stack_utils.c \
	psw_sort_utils.c

SRC_SORTS	= \
	psw_fool_sort.c \
	psw_merge_sort.c \
	psw_idx_sort.c \
	psw_quick_sort.c

SRCS	= $(addprefix $(SRCDIR), $(SRC_MAIN))
SRCS	+= $(addprefix $(SRCDIR)utils/, $(SRC_UTILS))
SRCS	+= $(addprefix $(SRCDIR)sorts/, $(SRC_SORTS))

OBJS	= $(addprefix $(OBJDIR), $(SRC_MAIN:.c=.o))
OBJS	+= $(addprefix $(OBJDIR), $(SRC_UTILS:.c=.o))
OBJS	+= $(addprefix $(OBJDIR), $(SRC_SORTS:.c=.o))
#LDFLAGS	=$(CFLAGS)

#CHK_LEAK_CC	= clang
#CHK_LEAK_FLAG	= -Wall -Wextra -Werror -g -fsanitize=leaks

#TESTER		= psw_tester
#TST_SRCS	= psw_tester.
#TST_OBJS	= $(TST_SRCS:.c=.o)

.PHONY:all re clean fclean test

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): $(SRCS)
	-mkdir -pv $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

#test: re $(TESTER)

#$(TESTER): $(TST_OBJS)

echo:
	@echo 