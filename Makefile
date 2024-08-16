NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = libs/mlx
LIBFT_DIR = libs/libft
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

RM = rm -f

# Regra padrão para compilar o projeto
all: libft mlx $(NAME)

# Regra para compilar a biblioteca libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Regra para compilar a biblioteca mlx
mlx:
	$(MAKE) -C $(MLX_DIR)

# Regra para compilar o executável
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Regra para limpar arquivos temporários
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

# Regra para limpar arquivos temporários e o executável
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(MLX_DIR)

# Regra para recompilar o projeto
re: fclean all

# Regra para executar o Valgrind
vg: $(NAME)
	valgrind ./$(NAME)

