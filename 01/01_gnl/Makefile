CC	:= gcc
FLG	:= -Wall -Wextra -Werror -g -fsanitize=address

B0	:= -D BUFFER_SIZE=0
B1	:= -D BUFFER_SIZE=1
B42	:= -D BUFFER_SIZE=42
B1024	:= -D BUFFER_SIZE=1024
B107	:= -D BUFFER_SIZE=10000000

SRC	:= get_next_line.c get_next_line_utils.c get_next_line.h gnl_main.c
BNS	:= get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.h gnl_main_bonus.c

.PHONY: all clean fclean re bonus

b0:
	$(CC) $(FLG) $(B0) $(SRC)

b1:
	$(CC) $(FLG) $(B1) $(SRC)

b2:
	$(CC) $(FLG) $(B42) $(SRC)

b3:
	$(CC) $(FLG) $(B1024) $(SRC)

b4:
	$(CC) $(FLG) $(B107) $(SRC)
