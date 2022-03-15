NAME=minitalk
SERVER=server
CLIENT=client
S_SRCS=$(SERVER).c server_utils.c common.c
C_SRCS=$(CLIENT).c client_utils.c common.c
S_OBJS=$(S_SRCS:.c=.o)
C_OBJS=$(C_SRCS:.c=.o)

CFLAGS=-Wall -Wextra -Werror
LDFLAGS=$(CFLAGS)

.PHONY: all $(NAME)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(S_OBJS)

$(CLIENT): $(C_OBJS)

fclean:
	$(RM) $(S_OBJS) $(C_OBJS) $(SERVER) $(CLIENT)

re: fclean all