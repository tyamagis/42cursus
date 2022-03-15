NAME=program_name
SRCS=$(NAME).c file_1.c file_2.c
OBJS=$(SRCS:.c=.o)
#CC=gcc
CFLAGS=-Wextra -Werror -Wall
LDFLAGS=$(CFLAGS)

$(NAME): $(OBJS)

.PHONY:all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all