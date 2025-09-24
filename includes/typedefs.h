/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:37:10 by rmhazres          #+#    #+#             */
/*   Updated: 2025/09/24 18:40:23 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

#include "cub3d.h"

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
    t_color floor;
    t_color ceiling;
    t_map   map;
    int player_x;
    int player_y;
    char player_dir;
} t_config;

#endif