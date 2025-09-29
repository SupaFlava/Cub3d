# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 15:04:17 by jbaetsen          #+#    #+#              #
#    Updated: 2025/09/29 18:41:24 by rmhazres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===================== #
#      Configuration    #
# ===================== #
CC      = cc
BREW_PREFIX = /opt/homebrew
#this is for apple silicon please dont remove it only comment it out

CFLAGS  = -Wall -Wextra -Werror -Iincludes \
          -Ilibft \
          -IMLX42/include \
		  -I$(BREW_PREFIX)/opt/glfw/include
#this is for apple silicon please dont remove it only comment it out
LDFLAGS = MLX42/build/libmlx42.a -Llibft -lft \
          -lglfw -ldl -pthread -lm -L$(BREW_PREFIX)/opt/glfw/lib \
	 	  -framework Cocoa -framework OpenGL -framework IOKit
#this is for apple silicon please dont remove it only comment it out

NAME    = cub3d

SRC_DIR = src
OBJ_DIR = obj

# ===================== #
#        Files          #
# ===================== #
SRC_MAIN = src/main.c

SRC_PARSE = src/parsing/arg_checker.c src/parsing/get_file.c src/parsing/parse_config.c

SRC_VALIDATION = src/validation/validate.c

SRC_MAP = 

SRC_RENDER = 

SRC_PLAYER = 

SRC_UTILS = src/utils/parsing_utils.c src/utils/memory_utils.c src/utils/cleanup_utils.c

SRC_ASSETS = 


SRC = $(SRC_MAIN) $(SRC_PARSE) $(SRC_MAP) $(SRC_VALIDATION) $(SRC_RENDER) $(SRC_PLAYER) $(SRC_UTILS) $(SRC_ASSETS)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft/libft.a




# ===================== #
#        Rules          #
# ===================== #

all: submodules $(NAME)

# --- Update submodules and build libraries ---
submodules:
	@git submodule update --init --recursive
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