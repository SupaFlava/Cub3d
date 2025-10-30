/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:06:21 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/29 20:02:41 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_solid_tile(t_game *game, int target_x, int target_y)
{
	if (target_x < 0 || target_x >= game->map.width
		|| target_y < 0 || target_y >= game->map.width)
		return (1);
	return (game->map.grid[target_y][target_x] == '1');
}

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
