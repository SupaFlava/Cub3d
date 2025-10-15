/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:07:58 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/15 23:57:48 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	t_config	config;

	// ####################PARSING BLOCK#################################//
	if (arg_checker(argc, argv) == FAILURE)
		return (FAILURE);
	if (get_file(argv[1], &config) == FAILURE)
		return (FAILURE);
	init_config(&config);
	if (parse_game(&config) == FAILURE)
	{
		ft_printf("NOT TRIGGERED ???\n");
		return (FAILURE);
	}
	//####################PARSING BLOCK#################################//

	//####################GAME BLOCK#################################//
	if (init_game(&game, &config) != EXIT_SUCCESS)
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
