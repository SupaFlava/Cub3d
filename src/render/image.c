/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 16:46:18 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/01 20:57:20 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	create_background_image(t_game *game)
// {
// 	game->assets->background = mlx_new_image(game->mlx, 1920, 1080);
// 	if (!game->assets->background)
// 		return (0);
// 	memset(game->assets->background->pixels, 0, 1920 * 1080 * BPP);
// 	return (1);
// }

// int	create_wall_image(t_game *game)
// {
// 	game->assets->wall = mlx_new_image(game->mlx, 1920, 1080);
// 	if (!game->assets->wall)
// 		return (0);
// 	memset(game->assets->wall->pixels, 30, 64 * 64 * BPP);
// 	return (1);
// }

// int	create_player_image(t_game *game)
// {
// 	game->assets->player = mlx_new_image(game->mlx, 50, 50);
// 	if (!game->assets->player)
// 		return (0);
// 	memset(game->assets->player->pixels, 255, 50 * 50 * BPP);
// 	return (1);
// }

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
