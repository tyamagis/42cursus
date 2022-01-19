C_NAME	:= client
S_NAME	:= server
CC		:= gcc
FLG		:= -Wall -Wextra -Werror

C_SRC	:= client_main.c
C_OBJ	:= $(C_SRC:.c=.o)

S_SRC	:= server_main.c
S_OBJ	:= $(S_SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(C_NAME) $(S_NAME)

$(C_NAME): $(C_OBJ)
	$(CC) $(FLG) $^ -o $(C_NAME)

$(S_NAME): $(S_OBJ)
	$(CC) $(FLG) $^ -o $(S_NAME)

.c.o:
	$(CC) $(FLG) -c $<

clean:
	rm -rf $(C_OBJ) $(S_OBJ)

fclean: clean
	rm -rf $(C_NAME) $(S_NAME)

re: fclean all
