/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:07:58 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/24 14:32:15 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game		game;
	t_config	config;

	if (handle_input(argc, argv, &config) == FAILURE)
		return (FAILURE);
	if (parse_game(&config) == FAILURE)
		return (FAILURE);

	if (init_game(&game, &config) != EXIT_SUCCESS)
	{
		ft_printf("error initializing game\n");
		return (EXIT_FAILURE); // no proper cleanup function made yet
	}
	images_to_window(&game);
	mlx_key_hook(game.mlx, keyhook, &game);
	// mlx_close_hook(game.mlx, clean_cub3d, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);

	clean_config(&config);
	clean_game(&game);
	mlx_terminate(game.mlx); //closes game loop  //these not needed if we clean in key_hook??
	return (EXIT_SUCCESS);
}
