NAME=program_name
OBJS=$(NAME).o file_1.o file_2.o
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