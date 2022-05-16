NAME = fdf
SRCS = main.c \
		vars.c \
		ft_parse.c \
		error.c \
		image.c \
		hook.c \
		rotation.c \
		limits.c \
		ft_sphere.c \
		segment.c \
		segment_bis.c
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT = make -C libft/
LIBFTFLAGS = -Llibft -lft -Ilibft
MLXFLAGS = -Lmlx -lmlx -lXext -lX11 -lm -lz -Imlx

all: $(NAME)

$(NAME):
	$(LIBFT) all
	$(CC) $(CFLAGS) $(SRCS) $(LIBFTFLAGS) $(MLXFLAGS) -o $(NAME)

clean:
	$(LIBFT) clean

fclean: clean
	$(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
