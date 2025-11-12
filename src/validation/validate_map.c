/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/30 14:27:58 by rmhazres      #+#    #+#                 */
/*   Updated: 2025/11/12 12:56:09 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stddef.h>

int	is_matching(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (SUCCESS);
	return (FAILURE);
}

int	flood_fill(t_config *config, int y, int x)
{
	size_t	row_len;
	char	**map;

	map = config->map.grid;
	if (x < 0 || y < 0)
		return (FAILURE);
	row_len = ft_strlen(map[y]);
	if (y >= config->map.height || x >= (int)row_len
		|| map[y][x] == ' ')
		return (FAILURE);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (SUCCESS);
	map[y][x] = 'V';
	if (!flood_fill(config, y - 1, x))
		return (FAILURE);
	if (!flood_fill(config, y + 1, x))
		return (FAILURE);
	if (!flood_fill(config, y, x - 1))
		return (FAILURE);
	if (!flood_fill(config, y, x + 1))
		return (FAILURE);
	return (SUCCESS);
}

int	map_char_check(t_config *config)
{
	int		i;
	int		j;

	i = 0;
	while (config->map.grid[i])
	{
		j = 0;
		while (config->map.grid[i][j])
		{
			if (!check_char(config, i, j))
				return (ft_printf("Error\nUnknown char or dup\n"), FAILURE);
			if (is_matching(config->map.grid[i][j]))
				set_position(config, i, j);
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

int	empty_space_fill(t_config *config)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < (size_t)config->map.height)
	{
		x = 0;
		while (config->map.grid[y] && x < ft_strlen(config->map.grid[y]))
		{
			if (config->map.grid[y][x] == '0')
			{
				if (!flood_fill(config, y, x))
				{
					ft_printf("Error\nMap is open!\n");
					return (FAILURE);
				}
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	validate_map(t_config *config)
{
	if (!config->map.height)
	{
		ft_printf("Error\nMap empty or doesnt exist!\n");
		return (FAILURE);
	}
	if (config->map.height > 1500 || config->map.width > 1500)
	{
		ft_printf("Error\nMap is to big");
		return (FAILURE);
	}
	if (!map_char_check(config))
		return (FAILURE);
	if (!flood_fill(config, config->player_y, config->player_x))
	{
		ft_printf("Error\nMap is open\n");
		return (FAILURE);
	}
	if (!empty_space_fill(config))
		return (FAILURE);
	if (!empty_line(config->map.grid))
		return (FAILURE);
	return (SUCCESS);
}

int	empty_line(char **str)
{
	int		i;
	bool	found;

	i = 0;
	found = false;
	while (ft_isspace(str[i]))
		i++;
	while (str[i])
	{
		if (found && !is_map_line(str[i]))
		{
			ft_printf("Error\nempty line detected\n");
			return (FAILURE);
		}
		if (ft_isspace(str[i]))
			found = true;
		i++;
	}
	return (SUCCESS);
}

