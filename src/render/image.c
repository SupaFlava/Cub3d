/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:46:18 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/16 22:39:34 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_image_overlay(t_game *game)
{
	if (!game->assets->fov)
		return ;
	ft_memset(game->assets->fov->pixels, 0, WIDTH * HEIGHT * BPP);
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

int	create_floor_ceiling_images(t_game *game, t_config *config)
{
	int x;
	int y;

	x = 0;
	y = 0;
	
	game->assets->floor = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2); // floor image
	if (!game->assets->floor)
		return (0);
	game->assets->ceiling = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2); // ceiling image
	if (!game->assets->ceiling)
		return (0);
	
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->assets->floor, x, y, 
				(config->floor.r << 24) | (config->floor.g << 16) | (config->floor.b << 8) | 0xFF);
			mlx_put_pixel(game->assets->ceiling, x, y, 
				(config->ceiling.r << 24) | (config->ceiling.g << 16) | (config->ceiling.b << 8) | 0xFF);
			x++;
		}
		y++;
	}
	return (1);
}

int	create_2dviewimages(t_game *game)
{
	//tiles are temp/ 2d view of map & player
	game->assets->background = make_tile(game->mlx, 0x808080FF);
	if (!game->assets->background)
		return (0);
	game->assets->wall = make_tile(game->mlx, 0xFF0000FF);
	if (!game->assets->wall)
		return (0);
	game->assets->player = make_tile(game->mlx, 0x0000FFFF);
	if (!game->assets->player)
		return (0);

	game->assets->fov = mlx_new_image(game->mlx, WIDTH, HEIGHT); // overlay image size of entire screen for the rays/fov
	if (!game->assets->fov)
		return 0;
	
	return (1);
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	(void)game;
	int	y;
	int	line_height;
	int draw_start;
	int draw_end;
	
	line_height = (int)(HEIGHT / ray->perp_dist);
	draw_start= -line_height / 2 + HEIGHT / 2;
	draw_end= line_height / 2 + HEIGHT / 2;

	if (draw_start < 0)
		draw_start = 0;
	if (draw_end < 0)
		draw_end = HEIGHT - 1;
	
	uint32_t color = (ray->side == 0) ? 0xFF00FFFF : 0x8800FFFF;
		
	y = draw_start;
	while (y < draw_end && y > 0)
	{
		if (y == 0)
		 	y = draw_start;
		mlx_put_pixel(game->assets->pov, x, y, color);
		y++;
	}
}
