/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:46:06 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/10 18:26:22 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_count(t_config *config, int i)
{
	int	count;

	count = 0;
	while (config->setting[i + count])
		count++;
	return (count);
}

int	extract_map(t_config *config, int i)
{
	int	j;
	int	count;
	int	width;
	char	*line;

	width = 0;
	j = 0;
	count = get_count(config, i);
	config->map.grid = malloc(sizeof(char *) *(count + 1));
	if (!config->map.grid)
		return (FAILURE);
	line = getnl_string(config->setting, &i);
	while (line)
	{
		config->map.grid[j] = ft_strdup(line);
		if (!config->map.grid[j])
			return (free(line),FAILURE);
		width = ft_strlen(config->map.grid[j]);
		if (width > config->map.width)
			config->map.width = width;
		j++;
		free(line);
		line = getnl_string(config->setting, &i);
	}
	config->map.grid[j] = NULL;
	config->map.height = count;
	return (SUCCESS);
}

int	assign_config(t_config *config, int dir, char **arr)
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
		if (!parse_color(config, arr[1], dir))
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
	if (!result[0] || !result[1] || result[2])
		return (clean_split(result), FAILURE);
	dir = classify_directive(result[0]);
	if (seen[dir])
	{
		clean_split(result);
		ft_printf("Error\nDuplicate or wrong config\n");
		return (FAILURE);
	}
	if (!assign_config(config, dir, result))
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
	int		count;
	char	*line;
	bool	seen[6];

	ft_memset(seen, 0, 6);
	i = 0;
	line = getnl_string(config->setting,&i);
	count = 0;
	while (line)
	{
		if (*line =='\0' || ft_isspace(line))
		{
			free(line);
			line = getnl_string(config->setting, &i);
			continue;	
		}
		else
		{
		if (!extract_config(config, line, seen))
			return(free(line),FAILURE);
		}
		free(line);
		count ++;
		if(count == 6)
			break;
		line = getnl_string(config->setting, &i);
	}
	if (!extract_map(config, i))
	{
		ft_printf("hererere\n");	
		return (FAILURE);
	}
	return (SUCCESS);
}
