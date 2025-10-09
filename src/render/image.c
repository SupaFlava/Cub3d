/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 16:46:18 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/09 13:31:51 by jbaetsen      ########   odam.nl         */
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
