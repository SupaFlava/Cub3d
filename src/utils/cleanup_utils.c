/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:19:36 by rmhazres          #+#    #+#             */
/*   Updated: 2025/09/29 17:30:54 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clean_split(char **alloc)
{
    int i;
    i = 0;
    while(alloc[i])
    {
        free(alloc[i]);
        i++;
    }
    free(alloc);
}

void	clean_config(t_config *config)
{
	if (config->no_tex)
		free(config->no_tex);
	if (config->so_tex)
		free(config->so_tex);
	if (config->we_tex)
		free(config->we_tex);
	if (config->ea_tex)
		free(config->we_tex);
	if (config->setting)
		clean_split(config->setting);
}
