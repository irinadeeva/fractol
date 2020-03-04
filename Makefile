
NAME = fractol

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3

SRC_D = ./src/
SRC =	$(SRC_D)fractol.c \
		$(SRC_D)menu.c \
		$(SRC_D)key.c \
		$(SRC_D)draw_fractol.c \


OBJ_D = ./obj/
OBJ = $(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

LIBFT_D = ./libft/
LIBFT = $(LIBFT_D)libft.a

MLX_D = ./mlx/
MLX = $(MLX_D)libmlx.a

INC_D = ./inc/
INC =	-I$(INC_D) \
		-I$(LIBFT_D) \
		-I$(MLX_D)  

LIB = $(LIBFT) $(MLX) -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME)

$(MLX):
	make -C $(MLX_D)

$(LIBFT):
	make -C $(LIBFT_D)

$(OBJ_D)%.o : $(SRC_D)%.c
	mkdir -p $(OBJ_D)
	$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	make -C $(LIBFT_D) clean
	make -C $(MLX_D) clean
	/bin/rm -rf $(OBJ_D);

fclean: clean
	make -C $(LIBFT_D) fclean
	make -C $(MLX_D) clean
	/bin/rm -rf $(NAME);

re: fclean all
