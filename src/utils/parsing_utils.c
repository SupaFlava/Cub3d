/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:19:01 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/13 14:19:52 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color(t_config *config, char *colors, int dir)
{
	char	**c_array;
	int		i;

	c_array = ft_split(colors, ',');
	if (!c_array)
		return (FAILURE);
	i = 0;
	while (c_array[i])
		i++;
	if (i != 3 || !ft_isnumeric(c_array))
		return (clean_split(c_array), FAILURE);
	if (dir == DIR_F)
	{
		config->floor.r = ft_atoi(c_array[0]);
		config->floor.g = ft_atoi(c_array[1]);
		config->floor.b = ft_atoi(c_array[2]);
	}
	else
	{
		config->roof.r = ft_atoi(c_array[0]);
		config->roof.g = ft_atoi(c_array[1]);
		config->roof.b = ft_atoi(c_array[2]);
	}
	clean_split(c_array);
	return (SUCCESS);
}

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' || line[i] != '0')
			return (false);
		i++;
	}
	return (true);
}

int	ft_isnl(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			i++;
		else
			return (FAILURE);
	}
	return (SUCCESS);
}

int	classify_directive(char *dir)
{
	char	*identifier[7];
	int		i;

	i = 0;
	identifier[0] = "NO";
	identifier[1] = "SO";
	identifier[2] = "WE";
	identifier[3] = "EA";
	identifier[4] = "F";
	identifier[5] = "C";
	identifier[6] = NULL;
	while (identifier[i])
	{
		if (ft_strncmp(identifier[i], dir, ft_strlen(dir)) == 0)
			return (i);
		i++;
	}
	return (DIR_INV);
}

void	set_position(t_config *config, int i, int j)
{
	config->player_x = j;
	config->player_y = i;
	config->player_dir = config->map.grid[i][j];
	config->map.p_count++;
}
