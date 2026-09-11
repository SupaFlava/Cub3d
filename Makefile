# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 15:04:17 by jbaetsen          #+#    #+#              #
#    Updated: 2026/09/11 12:08:56 by rmhazres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===================== #
#      Configuration    #
# ===================== #
CC      = cc
#this is for apple silicon please dont remove it only comment it out
BREW_PREFIX = /opt/homebrew

CFLAGS  = -Wall -Wextra -Werror -Iincludes -flto -O3 \
          -Ilibft \
          -IMLX42/include \
		  -I$(BREW_PREFIX)/opt/glfw/include
#this is for apple silicon please dont remove it only comment it out
LDFLAGS = MLX42/build/libmlx42.a -Llibft -lft \
          -lglfw -ldl -pthread -lm \
		  -L$(BREW_PREFIX)/opt/glfw/lib \
 	      -framework Cocoa -framework OpenGL -framework IOKit
#this is for apple silicon please dont remove it only comment it out

NAME    = cub3D
SRC_DIR = src
OBJ_DIR = obj

# ===================== #
#        Files          #
# ===================== #
SRC_MAIN = src/main.c

SRC_GAME = src/game/game.c src/game/controls.c

SRC_PARSE = src/parsing/arg_checker.c src/parsing/get_file.c src/parsing/parse_config.c src/parsing/parse_game.c src/parsing/handle_input.c

SRC_VALIDATION = src/validation/validate.c src/validation/validate_map.c

SRC_RAYS = src/raycasting/rays.c src/raycasting/casting.c src/raycasting/ray_math.c

SRC_RENDER = src/render/image.c src/render/render.c src/render/textures.c src/render/draw_column_utils.c

SRC_UTILS = src/utils/parsing_utils.c src/utils/memory_utils.c src/utils/cleanup_utils.c src/utils/init.c src/utils/cleanup.c \
			src/utils/validate_utils.c src/utils/controls_utils.c src/utils/math_utils.c src/utils/set_dir.c src/utils/flood_fill.c \
			src/utils/flood_fill_utils.c src/utils/parse_config_utils.c  src/utils/atoi_protected.c src/utils/setting_colors.c

SRC_ASSETS =

SRC = $(SRC_MAIN) $(SRC_GAME) $(SRC_PARSE) $(SRC_MAP) $(SRC_RAYS) $(SRC_VALIDATION) $(SRC_RENDER) $(SRC_PLAYER) $(SRC_UTILS) $(SRC_ASSETS)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft/libft.a

# ===================== #
#        Rules          #
# ===================== #

LIBFT_WEB = libft/libft_web.a
LIBFT_SRC := $(wildcard libft/*.c) $(wildcard libft/src/*.c)

$(LIBFT_WEB): $(LIBFT_SRC)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C libft CC=emcc AR=emar
	@mkdir -p libft
	@mv libft/libft.a $(LIBFT_WEB)

MLX_WEB_LIB = MLX42/build_web/libmlx42_web.a
WEB_OUT = web/cub3D.js

$(MLX_WEB_LIB):
	@cd MLX42 && emcmake cmake -B build_web
	@cd MLX42 && cmake --build build_web --parallel
	mv MLX42/build_web/libmlx42.a $(MLX_WEB_LIB)
	@cp ./MLX42/include/MLX42/MLX42.h ./includes
	@cp ./MLX42/include/MLX42/MLX42_Int.h ./includes

.PHONY: web-headers

web-headers:
	@cp ./MLX42/include/MLX42/MLX42.h ./includes
	@cp ./MLX42/include/MLX42/MLX42_Int.h ./includes

web: web-headers $(WEB_OUT)
WEB_HEADERS := $(wildcard includes/*.h)

$(WEB_OUT): $(SRC) $(WEB_HEADERS) $(MLX_WEB_LIB) $(LIBFT_WEB)
	mkdir -p web
	emcc -DWEB -O3 -Iincludes -Ilibft -IMLX42/include -MMD -MP $(SRC) \
		$(MLX_WEB_LIB) $(LIBFT_WEB) \
		-o $(WEB_OUT) \
		-msimd128 \
		-s USE_GLFW=3 \
		-s MIN_WEBGL_VERSION=2 -s MAX_WEBGL_VERSION=2 \
		-s WASM=1 \
		-s NO_EXIT_RUNTIME=1 \
		-s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' \
		-s ALLOW_MEMORY_GROWTH \
		-s INITIAL_MEMORY=67108864 \
		-s MAXIMUM_MEMORY=1073741824 \
		-s STACK_SIZE=2097152 \
		-s EXPORTED_FUNCTIONS='["_main","_web_lock_cursor"]' \
		--preload-file map@/map \
		--preload-file src/textures@/src/textures

all: submodules $(NAME)

# --- Update submodules and build libraries ---
submodules:
	@git submodule update --init --recursive
	@$(MAKE) -C libft
	@cmake -S MLX42 -B MLX42/build > /dev/null
	@cmake --build MLX42/build -j4 > /dev/null
	@cp ./MLX42/include/MLX42/MLX42.h ./includes
	@cp ./MLX42/include/MLX42/MLX42_Int.h ./includes

# --- Build final binary ---
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)
	@echo "✅ Build complete: $(NAME)"

$(OBJ): | submodules

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
	@rm -rf MLX42/build MLX42/build_web
	@rm -rf ./includes/MLX42.h
	@rm -rf ./includes/MLX42_Int.h
	@echo "🗑️  Full clean done"

re: fclean all

.PHONY: all clean fclean re submodules