/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 13:31:46 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/14 15:43:19 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// (dir_x, dir_y)
// (1, 0) = facing east
// (-1, 0) = facing west
// (0, 1) = facing south
// (0, -1) = facing north
void	set_player_start(t_game *game, int x, int y,  char dir)
{
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;

	if (dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y =  0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
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
		while (x < ft_strlen(game->map.grid[y]))
		{
			c = game->map.grid[y][x];
			if (c == '1')
				mlx_image_to_window(game->mlx, game->assets->wall, x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_image_to_window(game->mlx, game->assets->background, x * TILE_SIZE, y * TILE_SIZE);
			if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
				set_player_start(game, x, y, c);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->assets->player,
							(int)game->player.pos_x * TILE_SIZE - game->assets->player->width / 2,
							(int)game->player.pos_y * TILE_SIZE - game->assets->player->height / 2);
	mlx_image_to_window(game->mlx, game->assets->fov, 0, 0); // overlay img to window (for rays)
}
