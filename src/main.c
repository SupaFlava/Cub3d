/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:07:58 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/09/24 18:45:47 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
    t_config cofig;
    
	if(arg_checker(argc, argv) == FAILURE)
        return (FAILURE);
    if(get_cub(argv[1], &cofig)== FAILURE)
        return(FAILURE);
    if(parse_cub(&cofig))
    return (0);
}
