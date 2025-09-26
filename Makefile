# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbaetsen <jbaetsen@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/09/23 15:04:17 by jbaetsen      #+#    #+#                  #
#    Updated: 2025/09/26 14:39:20 by jbaetsen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===================== #
#      Configuration    #
# ===================== #
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Iincludes \
          -Ilibft \
          -IMLX42/include

LDFLAGS = MLX42/build/libmlx42.a -Llibft -lft \
          -lglfw -ldl -pthread -lm

NAME    = cub3d

SRC_DIR = src
OBJ_DIR = obj

# ===================== #
#        Files          #
# ===================== #
SRC_MAIN = src/main.c

SRC_PARSE = 

SRC_MAP = 

SRC_RENDER = src/render/image.c

SRC_PLAYER = 

SRC_UTILS = src/utils/init.c src/utils/cleanup.c

SRC_ASSETS = 

SRC = $(SRC_MAIN) $(SRC_PARSE) $(SRC_MAP) $(SRC_RENDER) $(SRC_PLAYER) $(SRC_UTILS) $(SRC_ASSETS)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft/libft.a

# ===================== #
#        Rules          #
# ===================== #

all: submodules $(NAME)

# --- Update submodules and build libraries ---
submodules:
	@git submodule update --init --recursive --remote
	@$(MAKE) -C libft
	@cmake -S MLX42 -B MLX42/build > /dev/null
	@cmake --build MLX42/build -j4 > /dev/null
	@echo "✅ Submodules updated and built"

# --- Build final binary ---
$(NAME): $(OBJ) $(LIBFT) submodules
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