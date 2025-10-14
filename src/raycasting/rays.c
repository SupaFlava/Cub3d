/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/02 14:13:11 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/14 13:39:28 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	differential_analysis(t_game *game, t_ray *ray)
{
	t_player *p;


	// starting square
	p = &game->player;
	ray->map_x = (int)p->pos_x;
	ray->map_y = (int)p->pos_y;


	// this is to avoid division b 0 later
	if (ray->ray_dir_x == 0.0)
		ray->delta_dist_x = INFINITY;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);

	if (ray->ray_dir_y == 0.0)
		ray->delta_dist_y = INFINITY;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);

	//calculate step and side dist
	if (ray->ray_dir_x < 0.0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (p->pos_x -  ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x =  (ray->map_x + 1.0 - p->pos_x) * ray->delta_dist_x;
	}

	if (ray->ray_dir_y < 0.0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (p->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - p->pos_y) * ray->delta_dist_y;
	}

	//perform DDA
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}

		if (ray->map_x < 0 || ray->map_x >= game->map.width ||
			ray->map_y < 0 || ray->map_y >= game->map.height)
		{
			ray->hit = 1;
			break;
		}
	}
	if (ray->side == 0)
	{
		if (ray->ray_dir_x != 0.0)
			ray->perp_dist = (ray->map_x - p->pos_x + (1 - ray->step_x) / 2.0) / ray->ray_dir_x;
		else
			ray->perp_dist = INFINITY;
	}
	if (ray->perp_dist < 0.0)
		ray->perp_dist = 0.0;
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
	t_point	start;
	t_point	end;
	double	ray_len;

	start.x = (int)(game->player.pos_x * TILE_SIZE);
	start.y = (int)(game->player.pos_y * TILE_SIZE);

	for (i = 0; i < NUM_RAYS; i++)
	{
		// Only draw if perp_dist is valid and positive
		ray_len = game->player.rays[i].perp_dist;
		if (ray_len > 0.0 && ray_len != INFINITY)
		{
			ray_len *= TILE_SIZE;
			end.x = (int)(start.x + game->player.rays[i].ray_dir_x * ray_len);
			end.y = (int)(start.y + game->player.rays[i].ray_dir_y * ray_len);
			draw_line(game->assets->fov, start, end, 0xFFFFFFFF);
		}
	}
}
