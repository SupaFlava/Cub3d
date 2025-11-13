/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:38:21 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/13 00:10:28 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_inside_map(t_config *config, int y, int x)
{
	if (y < 0 || y >= config->map.height)
		return (false);
	if (x < 0 || x >= (int)ft_strlen(config->map.grid[y]))
		return (false);
	return (true);
}

bool	is_wall_or_visited(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (true);
	return (false);
}

bool	is_space_cell(char **map, int y, int x)
{
	if (map[y][x] == ' ')
		return (true);
	return (false);
}
