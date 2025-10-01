/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:27:58 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/01 14:53:56 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_matching(char c)
{
	
}
int	map_char_check(char **map)
{
	int	i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'P'
				&& map[i][j] != 'W' && map[i][j] != 'E'
				&& map[i][j] != 'S' && map[i][j] != ' ')
			{
				ft_printf("Error\n Unknown charecter %c \n", map[i][j]);
				return (FAILURE);	
			}
			j++;
		}
		i++;
	}
	return(SUCCESS);
}

int validate_map(t_config *config)
{
	if(!config->map.height)
	{
		ft_printf("Error\nmap empty or doesnt exist!\n");
		return (FAILURE);
	}
	if (map_char_check(config->map.grid) == FAILURE)
		return(FAILURE);
	
	return (SUCCESS);
}
