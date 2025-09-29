/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:07:58 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/09/29 18:01:47 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_config(t_config *config)
{
	config->no_tex = NULL;
	config->so_tex = NULL;
	config->we_tex = NULL;
	config->ea_tex = NULL;
    config->err_flag = false;
	config->map.grid = (char **)malloc(sizeof(char * ));
	if(!config->map.grid)
		return (FAILURE);
}

int	main(int argc, char *argv[])
{
    t_config config;
    
	if(arg_checker(argc, argv) == FAILURE)
        return (FAILURE);
    if(get_file(argv[1], &config) == FAILURE)
        return(FAILURE);
	init_config(&config);
    parse_config(&config);
	validate(&config);
    return (0);
}
