/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 13:31:46 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/27 16:47:11 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *game, mlx_image_t *minimap)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.grid[y][x])
		{
			c = game->map.grid[y][x];
			if (c == '1')
				draw_tile(minimap, x, y, 0x000000FF);
			if (c == '0' || c == 'N' || c == 'E' || c == 'W' || c == 'S')
				draw_tile(minimap, x, y, 0x0000FFFF);
			x++;
		}
		y++;
	}
}

// void	render_map(t_game *game)
// {
// 	size_t	x;
// 	int		y;
// 	char	c;

// 	y = 0;
// 	x = 0;
// 	while (y < game->map.height)
// 	{
// 		x = 0;
// 		while (x < ft_strlen(game->map.grid[y]))
// 		{
// 			c = game->map.grid[y][x];
// 			if (c == '1')
// 				mlx_image_to_window(game->mlx, game->assets->wall, x * 10, y * TILE_SIZE);
// 			else if (game->map.grid[y][x] == '0')
// 				mlx_image_to_window(game->mlx, game->assets->floor2d, x * TILE_SIZE, y * TILE_SIZE);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_image_to_window(game->mlx, game->assets->player,
// 							(int)game->player.pos_x * TILE_SIZE - game->assets->player->width / 2,
// 							(int)game->player.pos_y * TILE_SIZE - game->assets->player->height / 2);
// 	mlx_image_to_window(game->mlx, game->assets->fov, 0, 0); // overlay img to window (for rays)
// }

void	images_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->assets->floor, 0, HEIGHT / 2); // floor image
	mlx_image_to_window(game->mlx, game->assets->ceiling, 0, 0); // ceiling image
	mlx_image_to_window(game->mlx, game->assets->pov, 0, 0); //first person view
	mlx_image_to_window(game->mlx, game->assets->minimap, 0, 0); //minimap
	// render_map(game);
}
