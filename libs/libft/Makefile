NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LFFLAGS = -fPIE
SRC =	ft_strdup.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_strlen.c \
		ft_split.c \
		ft_itoa.c \
		get_next_line.c \
		ft_strncmp.c \
		ft_putstr.c \
		ft_strlen_n.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SRC)
	$(CC) $(CFLAGS) $(LFFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
