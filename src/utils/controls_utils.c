/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:14:11 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/05 12:55:17 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_collision(t_game *game, double x, double y)
{
	if (y < 0 || y >= game->map.height
		|| x < 0 || x >= game->map.width)
		return ;
	if (game->map.grid[(int)(game->player.pos_y)][(int)x] != '1')
		game->player.pos_x = x;
	if (game->map.grid[(int)y][(int) game->player.pos_x] != '1')
		game->player.pos_y = y;
}

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
