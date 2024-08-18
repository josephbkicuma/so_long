NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
I_DIR = -I$(MINILIBX_DIR) -I$(LIBFT_DIR)
LDFLAGS = -pie

MINILIBX_DIR = libs/minilibx-linux
LIBFT_DIR = libs/libft
SRC_DIR = src
OBJ_DIR = obj

MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

SRCS = $(SRC_DIR)/access_validate.c \
       $(SRC_DIR)/assets_validation.c \
       $(SRC_DIR)/free.c \
       $(SRC_DIR)/main.c \
       $(SRC_DIR)/make_map.c \
       $(SRC_DIR)/map_validation.c \
       $(SRC_DIR)/player_animation.c \
       $(SRC_DIR)/player_mov.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RM = rm -f

all: libft minilibx $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR) all

minilibx:
	$(MAKE) -C $(MINILIBX_DIR) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(I_DIR) $(LDFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re libft minilibx
