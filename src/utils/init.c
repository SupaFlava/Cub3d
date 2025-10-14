/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:51:59 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/14 12:35:00 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//dummy map for testing - remove later
static const char *raw_map[] = {
    "111111111111111111111111111111",
	"100000000000000000000000000001",
	"100000111111111110000000000001",
	"100000000000000000000000100001",
	"100000000000000000001000000001",
	"100000000111111000000010000001",
	"100000000000001000000000000001",
	"100000000000001000000000010001",
	"10000000000N001000000000000001",
	"100000000000001111110000000001",
	"100000000000000000000000000001",
	"100001110000000000000000000001",
	"100000000000000000000100000001",
	"100000000011100000000100000001",
    "101000110000000000000100000001",
    "100000000000000000000000000001",
    "111111111111111111111111111111",
    NULL
};

int	init_map(t_game *game)
{
	int	y;
	int h;

	y = 0;
	h = 0;
	while (game->map.grid[h])
		h++;

	game->map.height = h;
	game->map.width = ft_strlen(raw_map[0]);
	game->map.grid = malloc(sizeof(char *) * (h + 1));
	if (!game->map.grid)
		return (0);
	while (y < h)
	{
		game->map.grid[y] = ft_strdup(raw_map[y]);
		y++;
	}
	game->map.grid[h] = NULL;
	return (1);
}

void	init_player(t_player *player, t_config *config)
{
	player->pos_x = config->player_x;
	player->pos_y = config->player_y;
	ft_printf("position of the player x is '%i' and y is '%i'\n",player->pos_x ,player->pos_y);

	player->dir_x = 1.0;
	player->dir_y = 0.0;
	player->plane_y = 0.0;
	player->plane_x = 0.66;
	player->move_speed = 200.0;
	player->rot_speed = 1.00;
}

int	init_assets(t_game *game)
{
	game->assets = malloc(sizeof(t_assets));
	if (!game->assets)
		return (0);

	game->assets->background = make_tile(game->mlx, 0x808080FF);
	if (!game->assets->background)
		return (0);
	game->assets->wall = make_tile(game->mlx, 0xFF0000FF);
	if (!game->assets->wall)
		return (0);
	game->assets->player = make_tile(game->mlx, 0x0000FFFF);
	if (!game->assets->player)
		return (0);


	// create_background_image(game);
	// if (!game->assets->background)
	// 	return (0);
	// create_player_image(game);
	// if (!game->assets->player)
	// 	return (0);
	// create_wall_image(game);
	// if (!game->assets->wall)
	// 	return (0);
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
	ft_printf("position of the player x is '%i' and y is '%i'\n",config->player_x , config->player_y);
	init_player(&game->player, config);
	if (!init_assets(game))
	{
		ft_printf("init_assets failure\n");
		return (EXIT_FAILURE);
	}
	game->map.grid = config->map.grid;
	game->map.height = config->map.height;
	render_map(game);
	// images_to_window(game);
	return (EXIT_SUCCESS);
}
