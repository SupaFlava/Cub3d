/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 13:07:58 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/02 13:22:35 by jbaetsen      ########   odam.nl         */
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
	config->map.grid = (char **)malloc(sizeof(char * ));
	if(!config->map.grid)
		return (FAILURE);
	return (SUCCESS);
}

int	main(/*int argc, char *argv[]*/)
{
	t_game	game;
	// t_config config;

	// parsing logic comment this whole block if needed 
	
	// if(arg_checker(argc, argv) == FAILURE)
	// 	return (FAILURE);
	// if(get_file(argv[1], &config) == FAILURE)
	// 	return(FAILURE);
	// init_config(&config);
	// parse_config(&config);
	// validate(&config);
	
	// parsing logic comment this whole block if needed ^^^^


	if (init_game(&game) != EXIT_SUCCESS) // sets up game struct and creates assets, and sets player variables
	{
		ft_printf("error initializing game\n");
		return (EXIT_FAILURE); // no proper cleanup function made yet
	}

	mlx_loop_hook(game.mlx, game_loop, &game); //game loop - keydown registration and refresh player image
	mlx_key_hook(game.mlx, keyhook, &game); //only checks ESC key
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx); //closes game loop
	return (EXIT_SUCCESS);
}
