# Nome do executável
NAME = so_long

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -pie

# Diretórios
MINILIBX_DIR = libs/minilibx-linux
LIBFT_DIR = libs/libft
SRC_DIR = src

# Flags da MinilibX
MLX_FLAGS = -fPIE -I$(MINILIBX_DIR) -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

# Arquivos fonte e objetos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

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
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

# Regra para compilar arquivos .c em .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(MINILIBX_DIR) -I$(LIBFT_DIR) -c $< -o $@

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
