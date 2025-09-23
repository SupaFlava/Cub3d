# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbaetsen <jbaetsen@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/09/23 15:04:17 by jbaetsen      #+#    #+#                  #
#    Updated: 2025/09/23 15:07:10 by jbaetsen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===================== #
#     Configuration     #
# ===================== #
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Iincludes \
          -Ilibraries/libft \
          -Ilibraries/mlx42/include

LDFLAGS = -Llibraries/mlx42/build -lmlx42 \
          -Llibraries/libft -lft \
          -lglfw -ldl -pthread -lm

NAME    = cub3d

SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = libraries

# ===================== #
#         Files         #
# ===================== #
SRC = $(shell find $(SRC_DIR) -name "*.c")
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = /libft/libft.a
MLX42 = /mlx42/build/libmlx42.a

# ===================== #
#         Rules         #
# ===================== #

all: submodules $(NAME)

# --- Update and build submodules ---
submodules:
	@git submodule update --init --recursive --remote
	@$(MAKE) -C libft
	@cmake -S MLX42 -B MLX42/build > /dev/null
	@cmake --build MLX42/build -j4 > /dev/null
	@echo "✅ Submodules updated and built"

# --- Final binary ---
$(NAME): $(OBJ) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)
	@echo "✅ Build complete: $(NAME)"

# --- Compile source files ---
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

# --- Clean rules ---
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C libft clean
	@echo "🧹 Objects cleaned"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@rm -rf mlx42/build
	@echo "🗑️  Full clean done"

re: fclean all

.PHONY: all clean fclean re submodules
