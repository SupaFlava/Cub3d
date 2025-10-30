/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 16:46:18 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/30 16:14:35 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_image(mlx_image_t *img)
{
	if (!img)
		return ;
	ft_memset(img->pixels, 0, img->width * TILE * img->height * TILE * BPP);
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
		return (0);
	game->assets->roof = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2);
	if (!game->assets->roof)
		return (0);
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->assets->floor, x, y,
				(c->floor.r << 24) | (c->floor.g << 16) | (c->floor.b << 8) | 0xFF);
			mlx_put_pixel(game->assets->roof, x, y,
				(c->roof.r << 24) | (c->roof.g << 16) | (c->roof.b << 8) | 0xFF);
			x++;
		}
		y++;
	}
	return (1);
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	uint32_t		color;
	mlx_texture_t	*tex;
	int				tex_x;
	int				tex_y;
	double			wall_x;
	double			tex_pos;
	double			step;
	int				y;

	tex = pick_texture(game, ray);
	if (!tex)
		return ;
	line_height = (int)(HEIGHT / ray->perp_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end > HEIGHT - 1)
		draw_end = HEIGHT - 1;
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
	step = 1.0 * tex->height / line_height;
	tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= (int)tex->height)
			tex_y = tex->height - 1;
		tex_pos += step;
		color = get_texture_pixel(tex, tex_x, tex_y);
		mlx_put_pixel(game->assets->pov, x, y, color);
		y++;
	}
}
