/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 13:31:46 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/08 13:51:33 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_rays(t_player *player)
{
	int		i;
	double	camera_x;

	i = 0;
	while (i < NUM_RAYS)
	{
		camera_x = 2.0 * i / (double)NUM_RAYS - 1.0;
		player->rays[i].ray_dir_x = player->dir_x + player->plane_x * camera_x;
		player->rays[i].ray_dir_y = player->dir_y + player->plane_y * camera_x;
 		i++;
	}
}

void	draw_player_rays(t_game *game)
{
	int		i;
	double	ray_len;
	t_point	start;
	t_point	end;

	i = 0;
	ray_len = 15 * TILE_SIZE;

	start.x = (int)(game->player.pos_x  * TILE_SIZE);
	start.y = (int)(game->player.pos_y * TILE_SIZE);

	while (i < NUM_RAYS)
	{
		end.x = (int)(start.x + game->player.rays[i].ray_dir_x * ray_len);
		end.y = (int)(start.y + game->player.rays[i].ray_dir_y * ray_len);
		draw_line(game->assets->fov, start, end, 0xFFFFFFFF);
		i++;
	}
}

void	set_player_start(t_game *game, int x, int y)
{
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	char c;
	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			c = game->map.grid[y][x];
			if (c == '1')
				mlx_image_to_window(game->mlx, game->assets->wall, x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_image_to_window(game->mlx, game->assets->background, x * TILE_SIZE, y * TILE_SIZE);
			if (c == 'N')
				set_player_start(game, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->assets->player,
							(int)game->player.pos_x * TILE_SIZE - game->assets->player->width / 2,
							(int)game->player.pos_y * TILE_SIZE - game->assets->player->height / 2);
}
