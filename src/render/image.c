/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:46:18 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/05 14:59:02 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_image(mlx_image_t *img)
{
	if (!img)
		return ;
	ft_memset(img->pixels, 0, img->width * img->height * BPP);
}

void	draw_tile(mlx_image_t *minimap, int x, int y, uint32_t color)
{
	int			px;
	int			py;

	py = 0;
	while (py < TILE)
	{
		px = 0;
		while (px < TILE)
		{
			mlx_put_pixel(minimap, x * TILE + px, y * TILE + py, color);
			px++;
		}
		py++;
	}
}

int	create_background_imgs(t_game *game, t_config *c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->assets->floor = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2);
	if (!game->assets->floor)
		return (FAILURE);
	game->assets->roof = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2);
	if (!game->assets->roof)
		return (FAILURE);
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->assets->floor, x, y, (c->floor.r << 24)
				| (c->floor.g << 16) | (c->floor.b << 8) | 0xFF);
			mlx_put_pixel(game->assets->roof, x, y, (c->roof.r << 24)
				| (c->roof.g << 16) | (c->roof.b << 8) | 0xFF);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	t_draw_info		info;
	mlx_texture_t	*tex;

	tex = pick_texture(game, ray);
	if (!tex)
		return ;
	calc_wall_bounds(ray, &info);
	info.tex_x = calc_text_x(game, ray, tex);
	setup_text_sampling(&info, tex);
	draw_textured_column(game, tex, x, &info);
}
