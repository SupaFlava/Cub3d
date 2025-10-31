/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 13:07:58 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/30 17:06:51 by jbaetsen      ########   odam.nl         */
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
		clean_cub3d(&game);
	}
	images_to_window(&game);
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
