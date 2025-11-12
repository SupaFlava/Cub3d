/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:10:49 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/12 11:30:22 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_game(t_config *config)
{
	init_config(config);
	if (!parse_config(config))
	{
		ft_printf("Error\nParsing failed\n");
		return (clean_config(config), FAILURE);
	}
	// set_map_width(config);
	if (!validate(config))
		return (clean_config(config), FAILURE);
	return (SUCCESS);
}
