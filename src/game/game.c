/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 11:23:55 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/30 13:55:35 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("CLOSING\nescape key pressed\n");
		clean_cub3d(game);
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
	check_movement(game, move_step);
	check_rotation(game, rot_step);
	ft_memset(game->assets->pov->pixels, 0, WIDTH * HEIGHT * BPP);
	draw_minimap(game, game->assets->minimap);
	draw_minimap_player(game);
	update_player_rays(&game->player);
	cast_rays_loop(game);
	draw_minimap_rays(game);
	draw_pov(game);
}
