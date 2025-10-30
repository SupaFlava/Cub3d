/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_math.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/23 16:21:00 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/30 14:29:41 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_ray_dir(t_ray *ray)
{
	if (ray->ray_dir_x == 0.0)
		ray->delta_dist_x = INFINITY;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0.0)
		ray->delta_dist_y = INFINITY;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
}

void	perform_dda(t_game *game, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= game->map.width
			|| ray->map_y < 0 || ray->map_y >= game->map.height)
		{
			ray->hit = 1;
			break ;
		}
		if (game->map.grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calc_perp_dist(t_ray *ray, t_player *p)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x != 0.0)
			ray->perp_dist = (ray->map_x - p->pos_x + (1 - ray->step_x) / 2.0)
				/ ray->ray_dir_x;
		else
			ray->perp_dist = INFINITY;
	}
	else
	{
		if (ray->ray_dir_x != 0.0)
			ray->perp_dist = (ray->map_y - p->pos_y + (1 - ray->step_y) / 2.0)
				/ ray->ray_dir_y;
		else
			ray->perp_dist = INFINITY;
	}
}

void	calc_side_dist(t_ray *ray, t_player *p)
{
	if (ray->ray_dir_x < 0.0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (p->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - p->pos_x) * ray->delta_dist_x;
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
}
