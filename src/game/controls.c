/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 16:00:33 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/31 16:28:22 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_mouse(t_game *game)
{
	double	mouse_rot;
	double	smooth_mouse_rot;

	if (fabs(game->player.pending_movement) > 0.001)
	{
		mouse_rot = game->player.pending_movement * game->player.mouse_sens;
		smooth_mouse_rot = mouse_rot * 0.8 + mouse_rot * 0.2;
		rotate_player(&game->player, smooth_mouse_rot);
		game->player.pending_movement = 0;
	}
}

void	mouse_look(double x_pos, double y_pos, void *param)
{
	t_game		*game;
	t_player	*player;
	double		delta_x;

	(void)y_pos;
	game = param;
	player = &game->player;
	if (!player->mouse_init)
	{
		player->last_mouse_x = x_pos;
		player->mouse_init = true;
		return ;
	}
	delta_x = x_pos - player->last_mouse_x;
	player->last_mouse_x = x_pos;
	game->player.pending_movement += delta_x;
}

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
