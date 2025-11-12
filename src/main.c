/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:07:58 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/11 13:29:29 by jbaetsen         ###   ########.fr       */
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
		ft_printf("error initializing game\n");
		clean_cub3d(&game);
	}
	if (!images_to_window(&game))
	{
		ft_printf("error putting image to window\n");
		clean_cub3d(&game);
	}
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_cursor_hook(game.mlx, mouse_look, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	clean_cub3d(&game);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
