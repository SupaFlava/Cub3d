/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:30:21 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/22 16:48:37 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_game *game, t_config *config)
{
	ft_printf("in load texture \n");
	game->assets->north_tex = mlx_load_png(config->no_tex);
	if (!game->assets->north_tex)
	{
		ft_printf("north texture didn't load\n");
		return (0);
	}
	game->assets->south_tex = mlx_load_png(config->so_tex);
	if (!game->assets->south_tex)
	{
		ft_printf("south texture didn't load\n");
		return (0);
	}
	game->assets->east_tex = mlx_load_png(config->ea_tex);
	if (!game->assets->east_tex)
	{
		ft_printf("east texture didn't load\n");
		return (0);
	}
	game->assets->west_tex = mlx_load_png(config->we_tex);
	if (!game->assets->west_tex)
	{
		ft_printf("west texture didn't load\n");
		return (0);
	}
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
	uint8_t	*pixel_data;
	int		index;
	uint8_t	r, g, b, a;
	uint32_t	color;

	// --- Safety check ---
	if (!tex)
		return (0xFFFFFFFF);
	if (x < 0 || y < 0 || x >= (int)tex->width || y >= (int)tex->height)
		return (0xFFFFFFFF);

	// --- Get starting index in texture pixel array ---
	index = (y * tex->width + x) * 4; // 4 bytes per pixel (RGBA)
	pixel_data = tex->pixels;

	// --- Read RGBA components clearly ---
	r = pixel_data[index + 0];
	g = pixel_data[index + 1];
	b = pixel_data[index + 2];
	a = pixel_data[index + 3];

	// --- Combine back into a single uint32_t color (RGBA format) ---
	color = (r << 24) | (g << 16) | (b << 8) | a;

	return (color);
}
