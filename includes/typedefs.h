/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:37:10 by rmhazres          #+#    #+#             */
/*   Updated: 2025/09/26 18:05:24 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

#include "cub3d.h"

typedef enum e_dir_type
{
	DIR_NO,	//NO
	DIR_SO,	//SO
	DIR_WE,	//WE
	DIR_EA,	//EA
	DIR_F,	//F
	DIR_C,	//C
    DIR_INV, //invalid
} t_dir_type;

typedef struct s_color {
    int r;
    int g;
    int b;
} t_color;

typedef struct s_map{
    char **grid;
    int  width;
    int  height;
}   t_map;

typedef struct s_config {
    char **setting;
    char *no_tex;
    char *so_tex;
    char *we_tex;
    char *ea_tex;
	bool in_config;
	int		dubplicate;
    t_color floor;
    t_color ceiling;
    t_map   map;
    int player_x;
    int player_y;
    char player_dir;
} t_config;

#endif