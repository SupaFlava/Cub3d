/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 11:23:55 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/01 16:06:53 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("CLOSING\nescape key pressed\n");
		exit(EXIT_SUCCESS);
	}
}

void	game_loop(void *param)
{
	t_game	*game;
	double	move_step;

	game = param;
	move_step = game->player.move_speed * game->mlx->delta_time;

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		game->player.pos_y -= move_step;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->player.pos_x -= move_step;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		game->player.pos_y += move_step;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->player.pos_x += move_step;





	game->assets->player->instances[0].x = (int32_t)game->player.pos_x;
	game->assets->player->instances[0].y = (int32_t)game->player.pos_y;
}
