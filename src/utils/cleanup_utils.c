/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:19:36 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/14 10:57:12 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clean_split(char **alloc)
{
	int i;

	i = 0;
	while (alloc[i])
	{
		free(alloc[i]);
		i++;
	}
	free(alloc);
	alloc = NULL;
}

void	clean_config(t_config *config)
{
	if (config->no_tex)
	{
		free(config->no_tex);
		config->no_tex = NULL;
	}
	if (config->so_tex)
	{
		free(config->so_tex);
		config->so_tex = NULL;
	}
	if (config->we_tex)
	{
		free(config->we_tex);
		config->we_tex = NULL;	
	}
	if (config->ea_tex)
	{
		free(config->ea_tex);
		config->ea_tex = NULL;
	}
	if (config->setting)
	{
		clean_split(config->setting);
		config->setting = NULL;
	}
	if (config->map.height != -1)
	{
		clean_split(config->map.grid);
		config->map.grid = NULL;
	}

}
