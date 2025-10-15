/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:46:18 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/15 23:18:21 by jbaetsen         ###   ########.fr       */
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
