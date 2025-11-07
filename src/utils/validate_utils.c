/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:23:52 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/07 12:35:51 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_and_close_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR\n");
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

int	check_char(t_config *config, int i, int j)
{
	if (config->map.grid[i][j] != '0' && config->map.grid[i][j] != '1'
				&& config->map.grid[i][j] != 'N'
				&& config->map.grid[i][j] != 'W'
				&& config->map.grid[i][j] != 'E'
				&& config->map.grid[i][j] != 'S'
				&& config->map.grid[i][j] != ' ')
		return (FAILURE);
	return (SUCCESS);
}

int	ft_isnumeric(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!isdigit(str[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
