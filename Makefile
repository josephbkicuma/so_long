# Nome do executável
NAME = so_long

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
I_DIR = -I$(MINILIBX_DIR) -I$(LIBFT_DIR)
LDFLAGS = -pie

# Diretórios
MINILIBX_DIR = libs/minilibx-linux
LIBFT_DIR = libs/libft
SRC_DIR = src
OBJ_DIR = obj

# Flags da MinilibX
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

# Arquivos fonte
SRCS = $(SRC_DIR)/access_validate.c \
       $(SRC_DIR)/assets_validation.c \
       $(SRC_DIR)/free.c \
       $(SRC_DIR)/main.c \
       $(SRC_DIR)/make_map.c \
       $(SRC_DIR)/map_validation.c \
       $(SRC_DIR)/player_animation.c \
       $(SRC_DIR)/player_mov.c

# Arquivos objeto
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Comando para remover arquivos
RM = rm -f

# Regra padrão para compilar o projeto
all: libft minilibx $(NAME)

# Regra para compilar a biblioteca libft
libft:
	$(MAKE) -C $(LIBFT_DIR) all

# Regra para compilar a biblioteca minilibx
minilibx:
	$(MAKE) -C $(MINILIBX_DIR) all

# Regra para compilar o executável
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(I_DIR) $(LDFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

# Regra para compilar arquivos .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar arquivos temporários
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

# Regra para limpar arquivos temporários e o executável
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Regra para recompilar o projeto
re: fclean all

# Regra para executar o Valgrind
vg: $(NAME)
	valgrind ./$(NAME)

.PHONY: all clean fclean re vg libft minilibx
