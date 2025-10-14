/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 16:00:33 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/07 16:13:31 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_movement(t_game *game, double move_step)
{
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
}

void	check_rotation(t_game *game, double rot_step)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(&game->player, -rot_step);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(&game->player, rot_step);
}

void	rotate_player(t_player *p, double angle)
{
	double	old_dir_x = p->dir_x;
	double	old_plane_x = p->plane_x;

	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);

	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}