/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:23:55 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/03 17:27:24 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("CLOSING\nescape key pressed\n");
		// delete_images(game);
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	game_loop(void *param)
{
	t_game	*game;
	double	move_step;
	double	rot_step;

	double	old_dir_x;
	double	old_plane_x;

	game = param;
	move_step = game->player.move_speed * game->mlx->delta_time;
	rot_step = game->player.rot_speed * game->mlx->delta_time;
	
	//movement
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->player.pos_x += game->player.dir_x * move_step;
		game->player.pos_y += game->player.dir_y * move_step;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player.pos_x -= game->player.dir_x * move_step;
		game->player.pos_y -= game->player.dir_y * move_step;		
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->player.pos_x += game->player.dir_y * move_step;
		game->player.pos_y -= game->player.dir_x * move_step;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player.pos_x -= game->player.dir_y * move_step;
		game->player.pos_y += game->player.dir_x * move_step;
	}
	
	// player rotation
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-rot_step) - game->player.dir_y * sin(-rot_step);
		game->player.dir_y = old_dir_x * sin(-rot_step) + game->player.dir_y * cos(-rot_step);

		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(rot_step) - game->player.plane_x * sin(rot_step);
		game->player.plane_x = old_plane_x * sin(rot_step) + game->player.dir_x * cos(rot_step);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(rot_step) - game->player.dir_y * sin(rot_step);
		game->player.dir_y = old_dir_x * sin(rot_step) + game->player.dir_y * cos(rot_step);

		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(-rot_step) - game->player.plane_x * sin(-rot_step);
		game->player.plane_x = old_plane_x * sin(-rot_step) + game->player.dir_x * cos(-rot_step);
	}
	
	update_player_rays(&game->player);   // compute rays
    // render_map(game);                     // draw background/walls
    draw_player_rays(game);               // draw the ray overlay

	
	game->assets->player->instances[0].x = (int32_t)(game->player.pos_x * TILE_SIZE - game->assets->player->width / 2);
	game->assets->player->instances[0].y = (int32_t)(game->player.pos_y * TILE_SIZE - game->assets->player->height / 2);
}

