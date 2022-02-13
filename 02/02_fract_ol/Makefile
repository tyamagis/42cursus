NAME	:= fractol
CC		:= gcc
CFLG		:= -Wall -Wextra -Werror -O3
SRC		:= main.c init.c calc_frctl.c color_mode_a.c color_mode_b.c draw.c kb_hooks.c ms_hooks.c set_color.c
OBJ		:= $(SRC:.c=.o)
MLXDIR	:= minilibx-linux
MLX		:= -lmlx -lX11 -lXext -lm
MLXA	:= libmlx_Linux.a

.PHONY: all clean fcelan re

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./minilibx-linux
	$(CC) $(CFLG) $^ -L./$(MLXDIR) $(MLX) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) ./$(MLXDIR)/$(MLXA)

re: fclean all
