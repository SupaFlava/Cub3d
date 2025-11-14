/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:46:06 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/14 17:20:03 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_map(t_config *config, int i)
{
	int		j;
	int		count;
	char	*line;

	j = 0;
	line = getnl_string(config->setting, &i);
	while (line && ft_isnl(line))
		free_and_get_line(config, &line, &i);
	count = get_count(config, i);
	config->map.grid = malloc(sizeof(char *) * (count + 1));
	if (!config->map.grid)
		return (FAILURE);
	while (line)
	{
		config->map.grid[j] = ft_strdup(line);
		if (!config->map.grid[j])
			return (free(line), FAILURE);
		j++;
		free_and_get_line(config, &line, &i);
	}
	config->map.grid[j] = NULL;
	return (SUCCESS);
}

int	assign_config(t_config *config, int dir, char **arr, char *line)
{
	if (dir == DIR_NO)
		config->no_tex = safe_assign(arr[1], config->err_flag);
	else if (dir == DIR_SO)
		config->so_tex = safe_assign(arr[1], config->err_flag);
	else if (dir == DIR_WE)
		config->we_tex = safe_assign(arr[1], config->err_flag);
	else if (dir == DIR_EA)
		config->ea_tex = safe_assign(arr[1], config->err_flag);
	else if (dir == DIR_F || dir == DIR_C)
	{
		if (!parse_color(config, line, dir))
			return (ft_printf("Error\nColors malformated!\n"), FAILURE);
	}
	else if (dir == DIR_INV)
	{
		ft_printf("Error\nInvalid dir\n");
		return (FAILURE);
	}
	if (config->err_flag)
		return (FAILURE);
	return (SUCCESS);
}

int	extract_config(t_config *config, char *line, bool *seen)
{
	char	**result;
	int		dir;

	result = ft_split(line, ' ');
	if (!result)
		return (FAILURE);
	dir = classify_directive(result[0]);
	if ((!result[1] || result[2]) && (dir != DIR_C && dir != DIR_F))
		return (clean_split(result), FAILURE);
	if (seen[dir])
	{
		clean_split(result);
		ft_printf("Error\nDuplicate or wrong config\n");
		return (FAILURE);
	}
	if (!assign_config(config, dir, result, line))
	{
		clean_split(result);
		return (FAILURE);
	}
	seen[dir] = true;
	clean_split(result);
	return (SUCCESS);
}

int	parse_config(t_config *config)
{
	int		i;
	bool	seen[6];

	ft_memset(seen, 0, 6);
	i = 0;
	if (!process_config_lines(config, seen, &i))
		return (FAILURE);
	if (!extract_map(config, i))
		return (FAILURE);
	return (SUCCESS);
}
