/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:37:10 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/10 17:15:05 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include "cub3d.h"

// defines
# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60.0
# define NUM_RAYS 60

# define TILE_SIZE 64
# define INIT_FAILURE 2
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

// enums
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

// structs
typedef struct s_color {
	int r;
	int g;
	int b;
} t_color;

typedef struct s_point
{
	int	x;
	int	y;
} t_point;

typedef struct s_map{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_config {
	char	**setting;
	char	*no_tex;
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;
	bool	in_config;
	bool	*err_flag;
	t_color	floor;
	t_color	ceiling;
	t_map	map;
	int		player_x;
	int		player_y;
	char	player_dir;
} t_config;

typedef struct s_ray
{
	double	ray_dir_x; //current direction
	double	ray_dir_y;
	int		map_x; //current location
	int		map_y;
	double	side_dist_x; //distance to next X tile side
	double	side_dist_y; //distance to next Y tile side
	double	delta_dist_x; //how far in map units to go from 1 x_side to the next
	double	delta_dist_y; 
	int		step_x; // can be +1 or -1
	int		step_y;
	int		hit;  // 1 if ray hit a wall
	int		side; //0 = hit vertical (x) side, 1 = hit horizontal (y) side
	
	double	dist_to_wall; //distance between player and wall. (tile units)
} t_ray;

INFINITY 

typedef struct s_player
{
	float	pos_x;
	float	pos_y;

	double	dir_x;
	double	dir_y;

	double	plane_x; // camera plane / fov
	double	plane_y;

	double	move_speed;
	double	rot_speed;

	t_ray	rays[NUM_RAYS];
}	t_player;

typedef struct s_assets //pointers to the actual loaded images in memory
{
	mlx_image_t		*background; // mlx_image_t types are temporary for testing
	mlx_image_t		*player;
	mlx_image_t		*wall;
	mlx_image_t		*fov;

	mlx_texture_t	*brick_wall;
	mlx_texture_t	*crack_wall; //adapt these later to tex_so & tex_no etc
	// void	*tex_no;
	// void	*tex_so;
	// void	*tex_we;
	// void	*tex_ea;
	// int		floor_color;
	// int		ceiling_color;
}	t_assets;

typedef struct s_game
{
	mlx_t		*mlx;

	//t_config	config;
	t_map		map;
	t_player	player;
	t_assets	*assets;

}	t_game;

#endif