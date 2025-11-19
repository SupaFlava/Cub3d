/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:09:17 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/19 13:27:40 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_colors(int dir, char **arr, t_config *config)
{
	char *trimmed;

	trimmed = NULL;
	if (dir == DIR_F)
	{
		trimmed = ft_strtrim(arr[0], "F");
		if (!trimmed)
			return (FAILURE);
		config->floor.r = atoi_p(trimmed);
		config->floor.g = atoi_p(arr[1]);
		config->floor.b = atoi_p(arr[2]);
	}
	else
	{
		trimmed = ft_strtrim(arr[0], "C");
		if (!trimmed)
			return (FAILURE);
		config->roof.r = atoi_p(trimmed);
		config->roof.g = atoi_p(arr[1]);
		config->roof.b = atoi_p(arr[2]);
	}
	free(trimmed);
	return (SUCCESS);
}
