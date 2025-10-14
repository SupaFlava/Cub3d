/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 13:07:58 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/14 15:30:49 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_config(t_config *config)
{
	config->no_tex = NULL;
	config->so_tex = NULL;
	config->we_tex = NULL;
	config->ea_tex = NULL;
	config->err_flag = false;
	config->map.height = -1;
	config->map.width = -1;
	config->map.p_count = 0;
	config->player_x = 0;
	config->player_y = 0;
	return (SUCCESS);
}

int	main(/*int argc, char *argv[]*/)
{
	t_game	game;
	// t_config	config;

	// ####################PARSING BLOCK#################################//
	// if (arg_checker(argc, argv) == FAILURE)
	// 	return (FAILURE);
	// if (get_file(argv[1], &config) == FAILURE)
	// 	return (FAILURE);
	// init_config(&config);

	// if (parse_game(&config) == FAILURE)
	// 	return (FAILURE);
	//####################PARSING BLOCK#################################//

	//####################GAME BLOCK#################################//
	if (init_game(&game) != EXIT_SUCCESS)
	 {
			ft_printf("error initializing game\n");
	 		return (EXIT_FAILURE); // no proper cleanup function made yet
 	}
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_key_hook(game.mlx, keyhook, NULL);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx); //closes game loop
	//####################GAME BLOCK#################################//

	// clean_config(&config);
	return (EXIT_SUCCESS);
}
