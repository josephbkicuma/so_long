NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
I_DIR = -I$(MINILIBX_DIR) -I$(LIBFT_DIR)
LDFLAGS = -pie

MINILIBX_DIR = libs/minilibx-linux
LIBFT_DIR = libs/libft
SRC_DIR = src
SRC_BONUS_DIR = src_bonus
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus

MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

# Arquivos fonte e objeto padrão
SRCS = $(SRC_DIR)/access_validate.c \
       $(SRC_DIR)/assets_validation.c \
       $(SRC_DIR)/free.c \
       $(SRC_DIR)/main.c \
       $(SRC_DIR)/make_map.c \
       $(SRC_DIR)/map_validation.c \
       $(SRC_DIR)/player_mov.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Arquivos fonte e objeto bônus
BONUS_SRCS = $(SRC_BONUS_DIR)/access_validate_bonus.c \
             $(SRC_BONUS_DIR)/assets_validation_bonus.c \
             $(SRC_BONUS_DIR)/free_bonus.c \
             $(SRC_BONUS_DIR)/main_bonus.c \
             $(SRC_BONUS_DIR)/make_map_bonus.c \
             $(SRC_BONUS_DIR)/map_validation_bonus.c \
             $(SRC_BONUS_DIR)/player_animation_bonus.c \
             $(SRC_BONUS_DIR)/player_mov_bonus.c

BONUS_OBJS = $(BONUS_SRCS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

RM = rm -f

all: libft minilibx $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR) all

minilibx:
	$(MAKE) -C $(MINILIBX_DIR) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(I_DIR) $(LDFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

bonus: $(BONUS_OBJS) all
	$(CC) $(CFLAGS) $(I_DIR) $(LDFLAGS) -o $(NAME)_bonus $(BONUS_OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME)_bonus
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re libft minilibx bonus
