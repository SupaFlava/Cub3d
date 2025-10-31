/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/26 13:51:59 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/31 13:48:52 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_dir(t_game *game, char dir)
{
	if (dir == 'N')
		set_north(game);
	else if (dir == 'S')
		set_south(game);
	else if (dir == 'W')
		set_west(game);
	else if (dir == 'E')
		set_east(game);
}

int	init_config(t_config *config)
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
	game->player.pos_x = config->player_x + 0.5;
	game->player.pos_y = config->player_y + 0.5;
	game->player.rot_speed = 3.0;
	game->player.move_speed = 3.0;
	set_player_dir(game, config->player_dir);
	game->player.last_mouse_x = 0;
	game->player.pending_movement = 0.0;
	game->player.mouse_sens = 0.002;
	game->player.mouse_init = false;
}

int	init_assets(t_game *game, t_config *config)
{
	game->assets = malloc(sizeof(t_assets));
	if (!game->assets)
		return (0);
	game->assets->pov = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->assets->pov)
		return (0);
	game->assets->minimap = mlx_new_image(game->mlx,
			config->map.width * TILE, config->map.height * TILE);
	if (!game->assets->minimap)
		return (0);
	if (!create_background_imgs(game, config))
		return (0);
	if (!load_textures(game, config))
	{
		ft_printf("Error loading textures");
		return (0);
	}
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
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
	game->config = config;
	game->map = config->map;
	init_player(game, config);
	if (!init_assets(game, config))
	{
		ft_printf("init_assets failure\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
