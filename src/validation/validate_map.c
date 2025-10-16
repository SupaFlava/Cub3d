/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:27:58 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/15 22:19:28 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_matching(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (SUCCESS);
	return (FAILURE);
}

int	flood_fill(t_config *config , int y, int x)
{
	int row_len;

	if (x < 0 || y < 0 )
		return (FAILURE);
	row_len = ft_strlen(config->map.grid[y]);
	if (y >= config->map.height || x >= row_len 
		|| config->map.grid[y][x] == ' ')
		return (FAILURE);
	if (config->map.grid[y][x] == '1' || config->map.grid[y][x] == 'V')
		return (SUCCESS);
	config->map.grid[y][x] = 'V';
	if (flood_fill(config, y - 1, x) == FAILURE)
		return (FAILURE);
	if (flood_fill(config, y + 1, x) == FAILURE)
		return (FAILURE);
	if (flood_fill(config, y ,x - 1) == FAILURE)
		return (FAILURE);
	if (flood_fill(config, y,  x + 1) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	map_char_check(t_config *config)
{
	int	i;
	int j;

	i = 0;
	while (config->map.grid[i])
	{
		j = 0;
		while (config->map.grid[i][j])
		{
			if (config->map.grid[i][j] != '0' && config->map.grid[i][j] != '1'
				&& config->map.grid[i][j] != 'N'
				&& config->map.grid[i][j] != 'W'
				&& config->map.grid[i][j] != 'E'
				&& config->map.grid[i][j] != 'S'
				&& config->map.grid[i][j] != ' '
				&& config->map.grid[i][j] != '\t')
			{
				ft_printf("Error\nUnknown charecter\n");
				return (FAILURE);
			}
			if (is_matching(config->map.grid[i][j]) == SUCCESS)
			{
				config->player_x = j;
				config->player_y = i;
				config->player_dir = config->map.grid[i][j];
				config->map.p_count++;
			}
			j++;
		}
		i++;
	}
	if (config->map.p_count != 1)
	{
		ft_printf("Error\nplayer count on map%i\n", config->map.p_count);
		return (FAILURE);
	}
	return (SUCCESS);
}

int validate_map(t_config *config)
{
	if (!config->map.height)
	{
		ft_printf("Error\nMap empty or doesnt exist!\n");
		return (FAILURE);
	}
	if (map_char_check(config) == FAILURE)
		return (FAILURE);
	if (flood_fill(config, config->player_y , config->player_x) == FAILURE)
	{
		ft_printf("map is busted\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
