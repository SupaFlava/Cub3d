/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:51:59 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/09/29 14:10:54 by jbaetsen         ###   ########.fr       */
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
	if (!game->assets)
		game->assets = malloc(sizeof(t_assets));
	if (!game->assets)
		return (EXIT_FAILURE);
		
	game->assets->background = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	memset(game->assets->background->pixels, 0, background->width * background->height * BPP);

	game->assets->player = mlx_new_image(game->mlx, 50, 50); //temp function, creates white square as player
	memset(game->assets->player->pixels, 255, player->width * player->height * BPP);

	if (mlx_image_to_window(game->mlx, player, 0, 0) < 0)
		return(EXIT_FAILURE);

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
	game->assets = NULL;
	init_player(&game->player);
	init_assets(game);
	return (EXIT_SUCCESS);
}