NAME	:= libft.a
CC		:= gcc
FLG	:= -Wall -Wextra -Werror

SRC		:= ft_atoi.c ft_bzero.c ft_calloc.c \
ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_strctrim.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJ		:= $(SRC:.c=.o)

BNS		:= ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c \
ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c \
ft_lstmap.c ft_lstiter.c
BOBJ	:= $(BNS:.c=.o)

.SUFFIXES: .c .o

.PHONY: all clean fclean re bonus
all: $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $^

.c.o:
	$(CC) $(FLG) -c $<

clean:
	rm -f $(OBJ) $(BOBJ) libft.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BOBJ) $(OBJ)
	ar r $(NAME) $^
