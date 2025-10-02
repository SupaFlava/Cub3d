/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 13:31:46 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/02 13:55:21 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_pos(t_game *game, int x, int y)
{
	game->player.pos_x = x +0.5;
	game->player.pos_y = y +0.5;
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	char c;
	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			c = game->map.grid[y][x];
			if (c == '1')
				mlx_image_to_window(game->mlx, game->assets->wall, x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_image_to_window(game->mlx, game->assets->background, x * TILE_SIZE, y * TILE_SIZE);
			if (c == 'N')
				set_player_pos(game, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->assets->player,
							(int)game->player.pos_x,
							(int)game->player.pos_y);
}
