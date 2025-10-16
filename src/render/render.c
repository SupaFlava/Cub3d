/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:31:46 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/15 23:38:27 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		while (x < ft_strlen(game->map.grid[y]))
		{
			if (c == '\t')
				x += 3;
			c = game->map.grid[y][x];
			if (c == '1')
				mlx_image_to_window(game->mlx, game->assets->wall, x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_image_to_window(game->mlx, game->assets->background, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->assets->player,
							(int)game->player.pos_x * TILE_SIZE - game->assets->player->width / 2,
							(int)game->player.pos_y * TILE_SIZE - game->assets->player->height / 2);
	mlx_image_to_window(game->mlx, game->assets->fov, 0, 0); // overlay img to window (for rays)
}
