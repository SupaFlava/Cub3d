/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   typedefs.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 21:37:10 by rmhazres      #+#    #+#                 */
/*   Updated: 2025/10/28 15:08:53 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include "cub3d.h"

// defines
# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60.0
# define NUM_RAYS WIDTH //this unnecary now? could just use WIDTH cause its the same
# define COL_WIDTH WIDTH / NUM_RAYS
# define TILE_SIZE 10

// # define INIT_FAILURE 2
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

// colors
# define RED     0xFF0000FF
# define GREEN   0x00FF00FF
# define BLUE    0x0000FFFF
# define WHITE   0xFFFFFFFF
# define BLACK   0x000000FF
# define YELLOW  0xFFFF00FF
# define CYAN    0x00FFFFFF
# define MAGENTA 0xFF00FFFF

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
    char **grid;
    int	width;
    int	height;
	int	p_count;
}   t_map;

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
	double	ray_dir_x;		//current direction
	double	ray_dir_y;
	int		map_x;			//current location
	int		map_y;
	double	side_dist_x;	//distance to next X tile side
	double	side_dist_y;	//distance to next Y tile side
	double	delta_dist_x;	//how far in map units to go from 1 x_side to the next
	double	delta_dist_y;	//how far in map units to go from 1 y_side to the next
	int		step_x;			// can be +1 or -1
	int		step_y;			// can be +1 or -1
	int		hit;			// 1 if hit a wall
	int		side;			//0 = hit vertical (x) side, 1 = hit horizontal (y) side

	double	perp_dist;		//distance between player and wall. (tile units)
} t_ray;


typedef struct s_player
{
	float	pos_x;
	float	pos_y;

	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	double	move_speed;
	double	rot_speed;

	t_ray	rays[NUM_RAYS];
}	t_player;

typedef struct s_assets
{

	//instead of these images, draw all this into 1 image > minimap
	// mlx_image_t		*floor2d;	// mlx_image_t types are  for 2d view
	// mlx_image_t		*player;	// 2d image for player icon
	// mlx_image_t		*wall;		// 2d image for wall tile

	//images
	mlx_image_t		*floor;		// bottom half of backround in 3d view
	mlx_image_t		*ceiling;	// top half of backround in 3d view
	mlx_image_t		*pov;		// 3d view image for rays

	mlx_image_t		*fov;		// overlay image for rays
	mlx_image_t		*minimap;


	// textures
	mlx_texture_t	*north_tex; // mlx_texture_t types are for wall textures in pov
	mlx_texture_t	*south_tex;
	mlx_texture_t	*west_tex;
	mlx_texture_t	*east_tex;
}	t_assets;

typedef struct s_game
{
	mlx_t		*mlx;

	t_map		map;
	t_player	player;
	t_assets	*assets;
	t_config	*config;

}	t_game;

#endif // TYPEDEFS_H