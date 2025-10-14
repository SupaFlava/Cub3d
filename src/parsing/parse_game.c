/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:10:49 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/14 12:05:03 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_game(t_config *config)
{
	if (parse_config(config) == FAILURE)
	{
		ft_printf("Error\nin parsing\n");
		return (clean_config(config),FAILURE);
	}
	if (validate(config) == FAILURE)
		return (clean_config(config),FAILURE);
	return (SUCCESS);
}
