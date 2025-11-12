/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 11:10:49 by rmhazres      #+#    #+#                 */
/*   Updated: 2025/11/12 13:49:24 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_map_size(t_config *config)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (config->map.grid[height])
	{
		width = ft_strlen(config->map.grid[height]);
		if (width > config->map.width)
			config->map.width = width;
		height++;
	}
	config->map.height = height;
}

int	parse_game(t_config *config)
{
	init_config(config);
	if (!parse_config(config))
	{
		ft_printf("Error\nParsing failed\n");
		return (clean_config(config), FAILURE);
	}
	set_map_size(config);
	if (!validate(config))
		return (clean_config(config), FAILURE);
	return (SUCCESS);
}
