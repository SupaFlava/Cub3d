/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:10:49 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/04 11:47:01 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_game(t_config *config)
{
	init_config(config);
	if (parse_config(config) == FAILURE)
	{
		ft_printf("Error\nparsing failed\n");
		return (clean_config(config), FAILURE);
	}
	if (validate(config) == FAILURE)
	{
		return (clean_config(config), FAILURE);
	}
	return (SUCCESS);
}
