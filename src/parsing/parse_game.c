/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:10:49 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/14 17:26:44 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_map_size(t_config *config)
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
	if (height < 0 || width < 0)
		return (FAILURE);
	return (SUCCESS);
}

int	parse_game(t_config *config)
{
	init_config(config);
	if (!parse_config(config))
	{
		ft_printf("Error\nParsing failed\n");
		return (clean_config(config), FAILURE);
	}
	if(!set_map_size(config))
		return (clean_config(config),FAILURE);
	if (!validate(config))
		return (clean_config(config), FAILURE);
	return (SUCCESS);
}
