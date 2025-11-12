/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 13:07:58 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/11/12 13:47:57 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game		game;
	t_config	config;

	if (!handle_input(argc, argv, &config))
		return (EXIT_FAILURE);
	if (!parse_game(&config))
		return (EXIT_FAILURE);
	if (!init_game(&game, &config))
	{
		clean_cub3d(&game, "error initializing game");
		return (EXIT_FAILURE);
	}
	if (!images_to_window(&game))
	{
		clean_cub3d(&game, "error putting image to window");
		return (EXIT_FAILURE);
	}
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_cursor_hook(game.mlx, mouse_look, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	clean_cub3d(&game, NULL);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
