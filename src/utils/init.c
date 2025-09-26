/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/26 13:51:59 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/09/26 14:38:49 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player) //initializes player position and angle + FOV
{
	player->pos_x = 100;
	player->pos_y = 100;
	player->dir_x = 1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.66; 
	player->move_speed = 0.1;
	player->rot_speed = 0.05;
}

int	init_assets(t_game *game)
{
	mlx_image_t *background; // mlx_image_t types are temporary for testing purposes
    mlx_image_t *player;
	

	background = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	memset(background->pixels, 0, background->width * background->height * BPP);
	if (mlx_image_to_window(game->mlx, background, 0, 0) < 0)
	{
		// mlx_delete_image(game->mlx, background);
		return (EXIT_FAILURE);
	}
	player = mlx_new_image(game->mlx, 50, 50);
	if (!player)
	{
		// mlx_delete_image(game->mlx, background); // move image deletion outside tihs function, if this function returns failure
		return (EXIT_FAILURE);
	}
	memset(player->pixels, 255, player->width * player->height * BPP);
	if (mlx_image_to_window(game->mlx, player, 0, 0) < 0)
	{
		// mlx_delete_image(game->mlx, background);
		// mlx_delete_image(mlx, player);
		return(EXIT_FAILURE);
	}
	// void	*tex_no;
	// void	*tex_so;
	// void	*tex_we;
	// void	*tex_ea;

	// int		floor_color;
	// int		ceiling_color;
	return (EXIT_SUCCESS);
}

int		init_game(t_game *game)
{
	// mlx_set_setting(MLX_MAXIMIZED, true);
	
	game->mlx = mlx_init(WIDTH, HEIGHT, "w0ffelstein", true);
	if (!game->mlx)
	{
		ft_printf("mlx_init failure\n");
		return (EXIT_FAILURE);
	}
		
	init_player(&game->player);
	init_assets(game);
	return (EXIT_SUCCESS);
}