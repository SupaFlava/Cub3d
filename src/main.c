/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:07:58 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/01 13:23:39 by rmhazres         ###   ########.fr       */
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
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
//	t_game	game;
	t_config config;

	// ####################PARSING BLOCK#################################//
	// parsing logic comment this whole block if needed 
	if(arg_checker(argc, argv) == FAILURE)
        return (FAILURE);
    if(get_file(argv[1], &config) == FAILURE)
	{
        return(FAILURE);	
	}
	init_config(&config);	
    if (parse_config(&config) == FAILURE)
		return(clean_config(&config),FAILURE);
	if(validate(&config) == FAILURE)
		return (clean_config(&config),FAILURE);
	clean_config(&config);

	// ####################PARSING BLOCK#################################//

	// ####################GAME BLOCK#################################//
	// if (init_game(&game) != EXIT_SUCCESS) // sets up game struct and creates assets, and sets player variables
	//  {
	// 		ft_printf("error initializing game\n");s
	//  		return (EXIT_FAILURE); // no proper cleanup function made yet
 	// }
	// mlx_loop_hook(game.mlx, game_loop, &game); //game loop - keydown registration and refresh player image
	// mlx_key_hook(game.mlx, keyhook, NULL); //only checks ESC key
	// mlx_loop(game.mlx);
	// mlx_terminate(game.mlx); //closes game loop
	// ####################GAME BLOCK#################################//

	
	return (EXIT_SUCCESS);
}
