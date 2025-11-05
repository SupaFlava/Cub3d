/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:10:49 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/05 16:09:39 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_game(t_config *config)
{
	init_config(config);
	if (!parse_config(config))
	{
		ft_printf("Error\nparsing failed\n");
		return (clean_config(config), FAILURE);
	}
	if (!validate(config))
		return (clean_config(config), FAILURE);
	return (SUCCESS);
}
