/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:00:35 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/04 12:57:27 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_assets(t_config *config)
{
	if (open_and_close_file(config->no_tex) == FAILURE)
	{
		ft_printf("north asset not found\n");
		return (FAILURE);
	}
	if (open_and_close_file(config->ea_tex) == FAILURE)
	{
		ft_printf("%s\n", config->ea_tex);
		ft_printf("east asset not found\n");
		return (FAILURE);
	}
	if (open_and_close_file(config->we_tex) == FAILURE)
	{
		ft_printf("west asset not found\n");
		return (FAILURE);
	}
	if (open_and_close_file(config->so_tex) == FAILURE)
	{
		ft_printf("south asset not found\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	check_colors(t_config *config)
{
	if (config->floor.r > 255 || config->floor.g < 0)
		return (FAILURE);
	if (config->floor.g > 255 || config->floor.g < 0)
		return (FAILURE);
	if (config->floor.b > 255 || config->floor.g < 0)
		return (FAILURE);
	if (config->roof.r > 255 || config->roof.g < 0)
		return (FAILURE);
	if (config->roof.g > 255 || config->roof.g < 0)
		return (FAILURE);
	if (config->roof.b > 255 || config->roof.g < 0)
		return (FAILURE);
	return (SUCCESS);
}

int	validate_config(t_config *config)
{
	if (check_assets(config) == FAILURE)
		return (FAILURE);
	if (check_colors(config) == FAILURE)
	{
		ft_printf("Error\n colors malformated\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	validate(t_config *config)
{
	if (validate_config(config) == FAILURE)
		return (FAILURE);
	if (validate_map(config) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
