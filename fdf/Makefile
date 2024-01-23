NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -o3
SRCS =  get_map.c color.c matrix_math.c connect_line.c fdf.c parse_coordinates.c
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw
MLXINCLUDE = MLX42/build/libmlx42.a -Iinclude -lglfw

OBJS = $(SRCS:.c=.o)

SUBDIR = LIBFT
MLX_REPO_URL = https://github.com/codam-coding-college/MLX42.git

all:  MLX42 $(NAME)

$(NAME): $(OBJS) $(SUBDIR) MLX42
	@$(MAKE) -C $(SUBDIR)
	@$(CC) $(OBJS) -L$(SUBDIR) -lft $(MLXFLAGS) $(MLXINCLUDE) -o $(NAME)

$(SUBDIR):
	@$(MAKE) -C $(SUBDIR)

MLX42:
	@if [ ! -d "MLX42" ]; then \
		git clone $(MLX_REPO_URL) MLX42; \
		cd MLX42 && cmake -B build && cd build && make && cd ../..; \
	else \
		echo "MLX already installed"; \
	fi

MLXR:
	rm -rf MLX42

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(SUBDIR) clean

fclean: clean
	rm -rf MLX42
	rm -f $(NAME)
	@$(MAKE) -C $(SUBDIR) fclean

re: fclean all

.PHONY: MLX42
