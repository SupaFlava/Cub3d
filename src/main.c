/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:07:58 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/09/26 14:33:48 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_config(t_config *config)
{
	config->no_tex = "";
	config->so_tex = "";
	config->we_tex = "";
	config->ea_tex = "";
}

int	main(int argc, char *argv[])
{
    t_config config;
    
	if(arg_checker(argc, argv) == FAILURE)
        return (FAILURE);
    if(get_file(argv[1], &config) == FAILURE)
	{
        return(FAILURE);
		
	}	
	init_config(&config);
    parse_config(&config);
    return (0);
}
