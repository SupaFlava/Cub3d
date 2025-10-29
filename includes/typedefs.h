/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:37:10 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/29 19:53:05 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include "cub3d.h"

// defines
# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60.0
# define TILE_SIZE 10
# define NUM_RAYS WIDTH

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
}	t_dir_type;

// structs
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		p_count;
}	t_map;

typedef struct s_config
{
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
}	t_config;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_dist;
}	t_ray;

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
	//images
	mlx_image_t		*floor;
	mlx_image_t		*ceiling;
	mlx_image_t		*pov;

	mlx_image_t		*fov;
	mlx_image_t		*minimap;

	// textures
	mlx_texture_t	*north_tex;
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