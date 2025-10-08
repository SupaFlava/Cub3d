/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 16:46:18 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/08 13:53:47 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_image_overlay(t_game *game)
{
	if (!game->assets->fov)
		return ;
	ft_memset(game->assets->fov->pixels, 0, WIDTH * HEIGHT * BPP);
}

void draw_line(mlx_image_t *img, t_point start, t_point end, uint32_t color)
{
	int dx = abs(end.x - start.x);
	int dy = -abs(end.y - start.y);
	int sx = start.x < end.x ? 1 : -1;
	int sy = start.y < end.y ? 1 : -1;
	int err = dx + dy;
	int e2;

	while (1)
	{
		if (start.x >= 0 && start.x < WIDTH && start.y >= 0 && start.y < HEIGHT)
			((uint32_t *)img->pixels)[start.y * WIDTH + start.x] = color;
		if (start.x == end.x && start.y == end.y)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			start.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			start.y += sy;
		}
	}
}

mlx_image_t	*make_tile(mlx_t *mlx, uint32_t color)
{
	mlx_image_t *img;
	int			x;
	int			y;

	x = 0;
	y = 0;
	img = mlx_new_image(mlx, TILE_SIZE, TILE_SIZE);
	if (!img)
		return (NULL);

	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
	return (img);
}

void	images_to_window(t_game *game)
{
	if (!game->assets)
		return ;
	mlx_image_to_window(game->mlx, game->assets->background, 0, 0);
	mlx_image_to_window(game->mlx, game->assets->player,
		(int)game->player.pos_x,
		(int)game->player.pos_y);
	mlx_image_to_window(game->mlx, game->assets->wall, 0, 0);
}
