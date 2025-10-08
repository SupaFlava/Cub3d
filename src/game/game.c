/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 11:23:55 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/08 13:26:56 by jbaetsen      ########   odam.nl         */
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

	game = param;
	move_step = game->player.move_speed * game->mlx->delta_time;
	rot_step = game->player.rot_speed * game->mlx->delta_time;

	//movement & rotation
	check_movement(game, move_step);
	check_rotation(game, rot_step);

	// ray overlay
	memset(game->assets->fov->pixels, 0, WIDTH * HEIGHT * BPP); //clears rays of previous frame
	update_player_rays(&game->player);	// calculates rays for next frame
	draw_player_rays(game);				// draws the pixels on assets->fov
	mlx_image_to_window(game->mlx, game->assets->fov, game->player.pos_x, game->player.pos_y); // puts assets->fov to screen
	//^^ this is janky as fuck and needs to be improved causing performance issues

	// updates player image locationm (temp)
	game->assets->player->instances[0].x = (int32_t)(game->player.pos_x * TILE_SIZE - game->assets->player->width / 2);
	game->assets->player->instances[0].y = (int32_t)(game->player.pos_y * TILE_SIZE - game->assets->player->height / 2);
}
