/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:13:11 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/05 14:31:58 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_rays(t_player *player)
{
	int		i;
	double	camera_x;

	i = 0;
	while (i < WIDTH)
	{
		camera_x = 2.0 * i / (double)(WIDTH -1) - 1.0;
		player->rays[i].ray_dir_x = player->dir_x + player->plane_x * camera_x;
		player->rays[i].ray_dir_y = player->dir_y + player->plane_y * camera_x;
		i++;
	}
}

void	init_line_variables(t_point *d, t_point *s, t_point start, t_point end)
{
	d->x = my_abs(end.x - start.x);
	d->y = -my_abs(end.y - start.y);
	if (start.x < end.x)
		s->x = 1;
	else
		s->x = -1;
	if (start.y < end.y)
		s->y = 1;
	else
		s->y = -1;
}

bool	is_in_bounds(mlx_image_t *img, t_point p)
{
	if (p.x < 0 || p.x >= (int)img->width)
		return (false);
	if (p.y < 0 || p.y >= (int)img->height)
		return (false);
	return (true);
}

void	draw_line(mlx_image_t *img, t_point start, t_point end, uint32_t color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	init_line_variables(&d, &s, start, end);
	err = d.x + d.y;
	while (1)
	{
		if (is_in_bounds(img, start))
			mlx_put_pixel(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
		{
			err += d.y;
			start.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			start.y += s.y;
		}
	}
}

void	draw_minimap_rays(t_game *game)
{
	int		i;
	t_point	start;
	t_point	end;
	double	ray_len;

	start.x = (int)(game->player.pos_x * TILE);
	start.y = (int)(game->player.pos_y * TILE);
	i = 0;
	while (i < WIDTH)
	{
		ray_len = game->player.rays[i].perp_dist;
		if (ray_len > 0.0 && ray_len != INFINITY)
		{
			ray_len *= TILE;
			end.x = (int)(start.x + game->player.rays[i].ray_dir_x * ray_len);
			end.y = (int)(start.y + game->player.rays[i].ray_dir_y * ray_len);
			draw_line(game->assets->minimap, start, end, WHITE);
		}
		i++;
	}
}
