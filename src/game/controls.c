/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 16:00:33 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/30 12:22:49 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_movement(t_game *game, double move_step)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forward(game, move_step);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_back(game, move_step);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game, move_step);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game, move_step);
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
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}
