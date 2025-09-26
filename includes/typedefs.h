/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   typedefs.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 21:37:10 by rmhazres      #+#    #+#                 */
/*   Updated: 2025/09/26 15:19:18 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

#include "cub3d.h"


// structs
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

typedef struct s_player
{
	float	pos_x;
	float	pos_y; //floats for position for more smooth movement.

	double	dir_x;
	double	dir_y;

	double	plane_x; // camera plane / player direction
	double	plane_y;

	double	move_speed;
	double	rot_speed;
} t_player;


typedef struct s_assets //pointers to the actual loaded images in memory
{
	mlx_image_t *background; // mlx_image_t types are temporary for testing purposes
	mlx_image_t *player;
	
	// void	*tex_no;
	// void	*tex_so;
	// void	*tex_we;
	// void	*tex_ea;

	// int		floor_color;
	// int		ceiling_color;
} t_assets;

typedef struct s_game
{
	void		*mlx;

	t_map		map;
	t_player	player;
	t_assets	assets;
	t_config	config;

} t_game;

#endif