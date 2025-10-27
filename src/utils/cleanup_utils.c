/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 17:19:36 by rmhazres      #+#    #+#                 */
/*   Updated: 2025/10/27 16:33:35 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (config->no_tex)
	{
		free(config->no_tex);
		config->no_tex = NULL;
	}
	if (config->so_tex)
	{
		free(config->so_tex);
		config->so_tex = NULL;
	}
	if (config->we_tex)
	{
		free(config->we_tex);
		config->we_tex = NULL;
	}
	if (config->ea_tex)
	{
		free(config->ea_tex);
		config->ea_tex = NULL;
	}
	if (config->setting)
	{
		clean_split(config->setting);
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
	if (game->assets->ceiling)
		mlx_delete_image(game->mlx, game->assets->ceiling);
	if (game->assets->pov)
		mlx_delete_image(game->mlx, game->assets->pov);
	if (game->assets->fov)
		mlx_delete_image(game->mlx, game->assets->fov);
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
