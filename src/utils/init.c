/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/26 13:51:59 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/16 14:05:12 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_dir(t_game *game, char dir)
{
	//split up into 4 different helper functions to save lines?
	if (dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y =  0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
}

int init_config(t_config *config)
{
	config->no_tex = NULL;
	config->so_tex = NULL;
	config->we_tex = NULL;
	config->ea_tex = NULL;
	config->err_flag = false;
	config->map.height = -1;
	config->map.width = -1;
	config->map.p_count = 0;
	config->player_x = 0;
	config->player_y = 0;
	return (SUCCESS);
}

void	init_player(t_game *game, t_config *config)
{
	game->player.pos_x = config->player_x;
	game->player.pos_y = config->player_y;
	game->player.rot_speed = 3.0;
	game->player.move_speed = 3.0;
	set_player_dir(game, config->player_dir);

	// init rays here?
}

int	init_assets(t_game *game, t_config *config)
{
	game->assets = malloc(sizeof(t_assets));
	if (!game->assets)
		return (0);

	game->assets->pov = mlx_new_image(game->mlx, WIDTH, HEIGHT); // first person POV image
	if (!game->assets->pov)
		return (0);
	
	if (!create_floor_ceiling_images(game, config))
		return (0);
	if (!create_2dviewimages(game)) // minimap assets and player
		return(0);
	if (!load_textures(game, config)) // textures loaded from files
		return (0);
	// textures_to_image() < todo
	return (1);
}

int	init_game(t_game *game, t_config *config)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "w0ffelstein", true);
	if (!game->mlx)
	{
		ft_printf("mlx_init failure\n");
		return (EXIT_FAILURE);
	}
	game->map = config->map;
	init_player(game, config);
	if (!init_assets(game, config))
	{
		ft_printf("init_assets failure\n");
		return (EXIT_FAILURE);
	}
	//  can technically clean config struct from here??
		return (EXIT_SUCCESS);
}
