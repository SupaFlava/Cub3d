/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:27:58 by rmhazres          #+#    #+#             */
/*   Updated: 2025/09/30 16:48:39 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int validate_map(t_config *config)
{
	if(!config->map.height)
	{
		ft_printf("Error\nmap empry or doesnt exist!\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
