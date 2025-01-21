# Nom du programme
NAME = fdf

# Répertoires
SRC_DIR = sources
INC_DIR = includes
LIBFT_DIR = libft
MLX_TAR = minilibx-linux.tgz
MLX_DIR = minilibx-linux

# Fichiers sources
SRC = $(shell find $(SRC_DIR) -name "*.c")
OBJ = $(SRC:.c=.o)

# Flags de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

# Flags pour MiniLibX
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lm -lXext -lX11

# Règles principales
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/libft.a $(MLX_FLAGS) -o $(NAME)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation de Libft
$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

# Compilation de MiniLibX
$(MLX_DIR)/libmlx.a:
	@make -C $(MLX_DIR)
	@echo "MiniLibX installed successfully!"
	

# Nettoyage
clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@if [ -d $(MLX_DIR) ]; then make clean -C $(MLX_DIR); fi
	@echo "Nettoyage des fichiers objects!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf ./minilibx-linux
	@echo "Netoyage complet!"

re: fclean all

# Règle pour décompresser MiniLibX (optionnel)
setup_mlx:
	@tar -xvzf minilibx-linux.tgz

.PHONY: all clean fclean re setup_mlx
