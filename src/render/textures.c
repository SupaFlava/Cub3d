/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:30:21 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/16 10:41:45 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_game *game, t_config *config)
{
	ft_printf("in LOad texture \n");
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

// void	texture_to_image(t_game *game)
// {
	
// }