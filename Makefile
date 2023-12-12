NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =  get_map.c color.c matrix_math.c connect_line.c fdf.c parse_coordinates.c
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
MLXINCLUDE = MLX42/build/libmlx42.a -Iinclude -lglfw

OBJS = $(SRCS:.c=.o)

SUBDIR = LIBFT

all: $(NAME)

$(NAME): $(OBJS) $(SUBDIR)
	@$(MAKE) -C $(SUBDIR)
	@$(CC) $(OBJS) -L$(SUBDIR) -lft $(MLXFLAGS) $(MLXINCLUDE) -o $(NAME)

$(SUBDIR):
	@$(MAKE) -C $(SUBDIR)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(SUBDIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(SUBDIR) fclean

re: fclean all
