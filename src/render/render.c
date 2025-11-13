/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 13:31:46 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/11/13 11:47:17 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pov(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		draw_column(game, &game->player.rays[i], i);
		i++;
	}
}

void	draw_minimap_player(t_game *game)
{
	int	px;
	int	py;
	int	radius;
	int	dx;
	int	dy;

	px = (int)(game->player.pos_x * TILE);
	py = (int)(game->player.pos_y * TILE);
	radius = 2;
	dx = -radius;
	while (dx <= radius)
	{
		dy = -radius;
		while (dy <= radius)
		{
			mlx_put_pixel(game->assets->minimap, px + dx, py + dy, RED);
			dy++;
		}
		dx++;
	}
}

void	draw_minimap(t_game *game, mlx_image_t *minimap)
{
	int		x;
	int		y;
	int		row_length;
	char	c;

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

int	images_to_window(t_game *game)
{
	int	pos;
	int	minimap_width;
	int	minimap_height;

	minimap_width = game->assets->minimap->width;
	minimap_height = game->assets->minimap->height;

	pos = HEIGHT / 2;
	if (mlx_image_to_window(game->mlx, game->assets->floor, 0, pos) == -1)
		return (FAILURE);
	if (mlx_image_to_window(game->mlx, game->assets->roof, 0, 0) == -1)
		return (FAILURE);
	if (mlx_image_to_window(game->mlx, game->assets->pov, 0, 0) == -1)
		return (FAILURE);
	if (minimap_width < WIDTH && minimap_height < HEIGHT)
	{
		if (mlx_image_to_window(game->mlx, game->assets->minimap, 0, 0) == -1)
			return (FAILURE);
	}
	return (SUCCESS);
}
