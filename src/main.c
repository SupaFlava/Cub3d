/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 13:07:58 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/09/26 15:09:54 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		print_and_exit(int code) // make this into a clean exit function later instead of
{
	if (code == INIT_FAILURE)
	{
		ft_printf("mlx_init failed");
		return (code);
	}
	return (0);
}

int	main(/*int argc, char *argv[]*/) //no parameters given yet
{
	t_game	game;
	

	if (init_game(&game) != EXIT_SUCCESS) // sets up game struct and creates assets, and sets player variables
	{
		ft_printf("error initializing game\n");
		return (EXIT_FAILURE); // no proper cleanup function made yet
	}
	mlx_key_hook(game.mlx, keyhook, NULL); //only checks ESC key

	mlx_loop(game.mlx); //game loop
	mlx_terminate(game.mlx); //closes game loop
	return (EXIT_SUCCESS);
}