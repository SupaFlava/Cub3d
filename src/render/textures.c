/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:30:21 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/05 14:32:23 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_game *game, t_config *config)
{
	game->assets->north_tex = mlx_load_png(config->no_tex);
	if (!game->assets->north_tex)
		return (FAILURE);
	game->assets->south_tex = mlx_load_png(config->so_tex);
	if (!game->assets->south_tex)
		return (FAILURE);
	game->assets->east_tex = mlx_load_png(config->ea_tex);
	if (!game->assets->east_tex)
		return (FAILURE);
	game->assets->west_tex = mlx_load_png(config->we_tex);
	if (!game->assets->west_tex)
		return (FAILURE);
	return (SUCCESS);
}

mlx_texture_t	*pick_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (game->assets->east_tex);
		else
			return (game->assets->west_tex);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (game->assets->south_tex);
		else
			return (game->assets->north_tex);
	}
}

uint32_t	get_texture_pixel(mlx_texture_t *tex, int x, int y)
{
	int			index;
	uint8_t		*pixel_data;
	t_color		pxl;
	uint32_t	color;

	if (!tex)
		return (WHITE);
	if (x < 0 || y < 0 || x >= (int)tex->width || y >= (int)tex->height)
		return (WHITE);
	index = (y * tex->width + x) * 4;
	pixel_data = tex->pixels;
	pxl.r = pixel_data[index + 0];
	pxl.g = pixel_data[index + 1];
	pxl.b = pixel_data[index + 2];
	pxl.a = pixel_data[index + 3];
	color = (pxl.r << 24) | (pxl.g << 16) | (pxl.b << 8) | pxl.a;
	return (color);
}
