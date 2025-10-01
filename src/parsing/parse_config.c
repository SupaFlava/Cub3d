/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:46:06 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/01 11:34:36 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_map(t_config *config, int i)
{
	int j;
	int	count;
	
	count = 0;
	j = 0;
	while(config->setting[i + count])
		count++;
	config->map.grid = malloc(sizeof(char *) *(count + 1));
	if(!config->map.grid)
		return (FAILURE);
	while(config->setting[i])
	{
		config->map.grid[j] = ft_strdup(config->setting[i]);
		if(!config->map.grid[j])
			return(FAILURE);
		i++;
		j++;
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
		if (parse_color(config ,arr[1],dir) == FAILURE)
			return (FAILURE);
	}
	else if (dir == DIR_INV)
	{
		ft_printf("Error\nInvalid dir\n");
		return (FAILURE);
	}
	if (config->err_flag)
	  	return(FAILURE);
	return (SUCCESS);
}

int	extract_config(t_config *config, char *line , bool *seen)
{
	char **result;
	int   dir;

	result = ft_split(line, ' ');
	if (!result)
		return(FAILURE);
	dir = classify_directive(result[0]);
	if(seen[dir])
	{
		ft_printf("Error\nDuplicate in config\n");
		return (FAILURE);
	}
	if (assign_config(config, dir, result) == FAILURE)
		return (FAILURE);
	seen[dir] = true;
	clean_split(result);
	return (SUCCESS);
}

int	parse_config(t_config *config)
{
	int	i;
	int config_len;
	bool seen[6] = {false, false, false, false, false, false};

	i = 0;
	config_len = 0;
	config->in_config = true;
	while(config->setting[i] && config->in_config)
	{
		if(ft_isspace(config->setting[i]) == SUCCESS)
			i++;
		else
		{
			if (extract_config(config,config->setting[i], seen) == FAILURE)
					return(FAILURE);
			config_len++;
			i++;
			if (config_len == 6)
				config->in_config = false;
		}
	}
	if(extract_map(config, i) == FAILURE)
		return(FAILURE);
	return (SUCCESS);
}
