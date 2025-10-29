/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 13:31:46 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/28 16:44:01 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void render_minimap_player(t_game *game)
{
	int px = (int)(game->player.pos_x * TILE_SIZE);
	int py = (int)(game->player.pos_y * TILE_SIZE);
	int radius = 2;
	int dx = -radius;

	while (dx <= radius)
	{
		int dy = -radius;
		while (dy <= radius)
		{
			mlx_put_pixel(game->assets->minimap,
				px + dx, py + dy, 0xFF0000FF); // Red player dot
			dy++;
		}
		dx++;
	}
}

void	draw_minimap(t_game *game, mlx_image_t *minimap)
{
	int		x;
	int		y;
	char	c;
	int	row_length;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		row_length = ft_strlen(game->map.grid[y]);
		while (x < game->map.width)
		{
			if (x < row_length)
				c = game->map.grid[y][x];
			else
				c = ' ';
			if (c == '1')
				draw_tile(minimap, x, y, YELLOW);
			else if (c == 'V')
				draw_tile(minimap, x, y, BLACK);
			x++;
		}
		y++;
	}
}

void	images_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->assets->floor, 0, HEIGHT / 2); // floor image
	mlx_image_to_window(game->mlx, game->assets->ceiling, 0, 0); // ceiling image
	mlx_image_to_window(game->mlx, game->assets->pov, 0, 0); //first person view
	mlx_image_to_window(game->mlx, game->assets->minimap, 0, 0); //minimap

}
