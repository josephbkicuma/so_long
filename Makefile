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

# Compilar a biblioteca libft
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: libft $(NAME)

# Regra para construir a biblioteca libft
libft:
	$(LIBFT_MAKE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

vg: $(NAME)
	valgrind ./$(NAME)
