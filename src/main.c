/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:07:58 by jbaetsen          #+#    #+#             */
/*   Updated: 2026/09/11 12:13:26 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef WEB
# include <emscripten.h>
# include <emscripten/html5.h>

EMSCRIPTEN_KEEPALIVE
void	web_lock_cursor(void)
{
	emscripten_request_pointerlock("#canvas", 1);
}
#endif


int	main(int argc, char *argv[])
{
	t_game		game;
	t_config	config;

#ifdef WEB
	char	*web_argv[] = {"cub3D", "map/valid/42.cub"};
	argc = 2;
	argv = web_argv;
#endif
	printf("MAIN START\n");

	if (!handle_input(argc, argv, &config))
		return (EXIT_FAILURE);
	printf("HANDLE INPUT OK\n");

	if (!parse_game(&config))
		return (EXIT_FAILURE);
	printf("PARSE GAME OK\n");

	if (!init_game(&game, &config))
	{
		clean_cub3d(&game, "error initializing game");
		return (EXIT_FAILURE);
	}
	printf("INIT GAME OK\n");

	if (!images_to_window(&game))
	{
		clean_cub3d(&game, "error putting image to window");
		return (EXIT_FAILURE);
	}
	printf("IMAGE OK\n");

	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_cursor_hook(game.mlx, mouse_look, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	printf("BEFORE MLX LOOP\n");

	mlx_loop(game.mlx);
	printf("AFTER MLX LOOP\n");
	clean_cub3d(&game, NULL);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}