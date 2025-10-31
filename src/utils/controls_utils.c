/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/29 20:14:11 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/30 16:46:13 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *game, double move_step)
{
	double	next_x;
	double	next_y;

	next_x = game->player.pos_x + game->player.dir_x * move_step;
	next_y = game->player.pos_y + game->player.dir_y * move_step;
	wall_collision(game, next_x, next_y);
}

void	move_back(t_game *game, double move_step)
{
	double	next_x;
	double	next_y;

	next_x = game->player.pos_x - game->player.dir_x * move_step;
	next_y = game->player.pos_y - game->player.dir_y * move_step;
	wall_collision(game, next_x, next_y);
}

void	move_left(t_game *game, double move_step)
{
	double	next_x;
	double	next_y;

	next_x = game->player.pos_x + game->player.dir_y * move_step;
	next_y = game->player.pos_y - game->player.dir_x * move_step;
	wall_collision(game, next_x, next_y);
}

void	move_right(t_game *game, double move_step)
{
	double	next_x;
	double	next_y;

	next_x = game->player.pos_x - game->player.dir_y * move_step;
	next_y = game->player.pos_y + game->player.dir_x * move_step;
	wall_collision(game, next_x, next_y);
}
