/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:06:21 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/24 14:13:25 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_solid_tile(t_game *game, int target_x, int target_y)
{
	if (target_x < 0 || target_x >= game->map.width ||
		target_y < 0 || target_y >= game->map.width)
		return (1);
	return (game->map.grid[target_y][target_x] == '1');
}

// int	try_move(t_game *game, double x, double y)
// {
// 	double new_x = game->player.pos_x + dx;
//     double new_y = game->player.pos_y + dy;
//     const double radius = 0.20; 

	
// }

void wall_collision(t_game *game, double x, double y)
{
	if (y < 0 || y >= game->map.height ||
    	x < 0 || x >= game->map.width)
    	return ;
	if (game->map.grid[(int)(game->player.pos_y)][(int)x] != '1')
		game->player.pos_x = x;
	if (game->map.grid[(int)y][(int) game->player.pos_x] != '1')
		game->player.pos_y = y;
}
