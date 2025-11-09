/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:19:36 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/09 20:35:46 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_and_null(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	clean_split(char **alloc)
{
	int	i;

	i = 0;
	while (alloc[i])
	{
		free(alloc[i]);
		i++;
	}
	free(alloc);
	alloc = NULL;
}

void	clean_config(t_config *config)
{
	if (!config)
		return ;
	if (config->no_tex)
		free_and_null(config->no_tex);
	if (config->so_tex)
		free_and_null(config->so_tex);
	if (config->we_tex)
		free_and_null(config->we_tex);
	if (config->ea_tex)
		free_and_null(config->ea_tex);
	if (config->setting)
	{
		free(config->setting);
		config->setting = NULL;
	}
	if (config->map.height != -1)
	{
		clean_split(config->map.grid);
		config->map.grid = NULL;
	}
}

void	clean_game(t_game *game)
{
	if (game->assets->roof)
		mlx_delete_image(game->mlx, game->assets->roof);
	if (game->assets->pov)
		mlx_delete_image(game->mlx, game->assets->pov);
	if (game->assets->north_tex)
		mlx_delete_texture(game->assets->north_tex);
	if (game->assets->south_tex)
		mlx_delete_texture(game->assets->south_tex);
	if (game->assets->west_tex)
		mlx_delete_texture(game->assets->west_tex);
	if (game->assets->east_tex)
		mlx_delete_texture(game->assets->east_tex);
	free(game->assets);
}

void	clean_cub3d(void *param)
{
	t_game	*game;

	game = param;
	clean_config(game->config);
	clean_game(game);
}
