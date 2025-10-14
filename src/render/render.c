/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:31:46 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/14 12:42:28 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_pos(t_game *game, int x, int y)
{
	game->player.pos_x = x * TILE_SIZE + (TILE_SIZE - TILE_SIZE) / 2;
	game->player.pos_y = y * TILE_SIZE + (TILE_SIZE - TILE_SIZE) / 2;
}

void	render_map(t_game *game)
{
	size_t	x;
	int	y;
	char c;

	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < ft_strlen(game->map.grid[x]))
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
