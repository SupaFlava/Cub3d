/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:13:11 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/10 17:16:14 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	differential_analysis(t_game *game, t_ray *ray)
{
	t_player *p;

	p = &game->player;
	ray->map_x = (int)p->pos_x
	ray->map_y = (int)p->pos_y

	if (ray->ray_dir_x == 0.0)
		ray->delta_dist
}

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