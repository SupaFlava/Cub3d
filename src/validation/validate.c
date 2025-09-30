/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:00:35 by rmhazres          #+#    #+#             */
/*   Updated: 2025/09/29 18:51:17 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_assets(t_config *config)
{
	int	fd;
	
	fd = open(config->no_tex, O_RDONLY);
	if(fd < 0)
	{
		ft_printf("%s \n", config->no_tex);
		ft_printf("failed for NORTH TEXT '%i' \n", fd);
		return(FAILURE);
	}
	ft_printf("what sucess ??? '%i' TEXT\n", fd);

	close(fd);
	return(SUCCESS);
}

int	validate_config(t_config *config)
{
	check_assets(config);
	return (SUCCESS);
}


int	validate(t_config *config)
{
	validate_config(config);
	// validate_map();
	return(SUCCESS);
}