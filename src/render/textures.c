/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 22:30:21 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/23 18:07:52 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_game *game, t_config *config)
{
	game->assets->north_tex = mlx_load_png(config->no_tex);
	if (!game->assets->north_tex)
		return (0);
	game->assets->south_tex = mlx_load_png(config->so_tex);
	if (!game->assets->south_tex)
		return (0);
	game->assets->east_tex = mlx_load_png(config->ea_tex);
	if (!game->assets->east_tex)
		return (0);
	game->assets->west_tex = mlx_load_png(config->we_tex);
	if (!game->assets->west_tex)
		return (0);
	return (1);
}

mlx_texture_t	*pick_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return(game->assets->east_tex);
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
	int		index;
	uint8_t	*pixel_data;
	uint8_t	r, g, b, a;
	uint32_t	color;

	if (!tex)
		return (0xFFFFFFFF);
	if (x < 0 || y < 0 || x >= (int)tex->width || y >= (int)tex->height)
		return (0xFFFFFFFF);
	// Get starting index in texture pixel array
	index = (y * tex->width + x) * 4;
	pixel_data = tex->pixels;
	// Read RGBA components clearly
	r = pixel_data[index + 0];
	g = pixel_data[index + 1];
	b = pixel_data[index + 2];
	a = pixel_data[index + 3];
	color = (r << 24) | (g << 16) | (b << 8) | a;
	return (color);
}
