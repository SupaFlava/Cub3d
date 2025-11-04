/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:31:00 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/04 22:56:17 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_wall_bounds(t_ray *ray, t_draw_info *info)
{
	info->line_height = (int)(HEIGHT / ray->perp_dist);
	info->draw_start = -info->line_height / 2 + HEIGHT / 2;
	info->draw_end = info->line_height / 2 + HEIGHT / 2;
	if (info->draw_start < 0)
		info->draw_start = 0;
	if (info->draw_end > HEIGHT - 1)
		info->draw_end = HEIGHT - 1;
}

int	calc_text_x(t_game *game, t_ray *ray, mlx_texture_t *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	setup_text_sampling(t_draw_info *info, mlx_texture_t *tex)
{
	info->step = 1.0 * tex->height / info->line_height;
	info->tex_pos = (info->draw_start - HEIGHT / 2 + info->line_height / 2)
		* info->step;
}

void	draw_textured_column(t_game *game, mlx_texture_t *tex, int x,
								t_draw_info *info)
{
	int			y;
	int			tex_y;
	uint32_t	color;

	y = info->draw_start;
	while (y < info->draw_end)
	{
		tex_y = (int)info->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= (int)tex->height)
			tex_y = tex->height - 1;
		info->tex_pos += info->step;
		color = get_texture_pixel(tex, info->tex_x, tex_y);
		mlx_put_pixel(game->assets->pov, x, y, color);
		y++;
	}
}
