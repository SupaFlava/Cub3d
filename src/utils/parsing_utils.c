/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:19:01 by rmhazres          #+#    #+#             */
/*   Updated: 2025/09/30 14:17:35 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    parse_color(t_config *config ,char *colors, int dir)
{
	char **c_array;
    int	i;
	
	c_array = ft_split(colors, ',');
	if(!c_array)
		return (FAILURE);
	i = 0;		
	while(c_array[i])
		i++;
	if(i != 3)
		return (ft_printf("Error\nColors malformated!\n"),FAILURE);
	if(dir == DIR_F)
	{
		config->floor.r = ft_atoi(c_array[0]);
		config->floor.g = ft_atoi(c_array[1]);
		config->floor.b = ft_atoi(c_array[2]);
	}
	else
	{
		config->ceiling.r = ft_atoi(c_array[0]);
		config->ceiling.g = ft_atoi(c_array[1]);
		config->ceiling.b = ft_atoi(c_array[2]);
	}
	clean_split(c_array);
	return (SUCCESS);
}

int ft_isspace(char *string)
{
	int i;
	
	i = 0;
	while(string[i])
	{
		if(string[i] == ' ' || string[i] == '\t')
			i++;
		else
			return(FAILURE); 
	}
	return(SUCCESS);
}

int classify_directive(char *dir)
{
	char *identifier[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int   i;

	i = 0;
	while(identifier[i])
	{
		if(ft_strncmp(identifier[i], dir, ft_strlen(identifier[i])) == 0)
			return(i);
		i++;
	}
	return (DIR_INV);
}
