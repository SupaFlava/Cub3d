/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:51:59 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/15 13:27:15 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//dummy map for testing - remove later
// static const char *raw_map[] = {
//     "111111111111111111111111111111",
// 	"100000000000000000000000000001",
// 	"10000S111111111110000000000001",
// 	"100000000000000000000000100001",
// 	"100000000000000000001000000001",
// 	"100000000111111000000010000001",
// 	"100000000000001000000000000001",
// 	"100000000000001000000000010001",
// 	"100000000000001000000000000001",
// 	"100000000000001111110000000001",
// 	"100000000000000000000000000001",
// 	"100001110000000000000000000001",
// 	"100000000000000000000100000001",
// 	"100000000011100000000100000001",
//     "101000110000000000000100000001",
//     "100000000000000000000000000001",
//     "111111111111111111111111111111",
//     NULL
// };

// int	init_map(t_game *game, t_map *map)
// {
// 	int	y;
// 	int h;

// 	y = 0;
// 	h = 0;
// 	// while (raw_map[h])
// 	// 	h++;

// 	game->map.height = map->height;
// 	game->map.width = ft_strlen(raw_map[0]);
// 	game->map.grid = malloc(sizeof(char *) * (h + 1));
// 	if (!game->map.grid)
// 		return (0);
// 	while (y < h)
// 	{
// 		game->map.grid[y] = ft_strdup(raw_map[y]);
// 		y++;
// 	}
// 	game->map.grid[h] = NULL;
// 	return (1);
// }

void	init_player(t_player *player)
{
	player->pos_x = 1.0;
	player->pos_y = 1.0;
	player->dir_x = 0.0;
	player->dir_y = -1.0;
	player->plane_y = 0.0;
	player->plane_x = 0.60; // fov
	player->move_speed = 3.0;
	player->rot_speed = 3.0;


}

int	init_assets(t_game *game)
{
	game->assets = malloc(sizeof(t_assets));
	if (!game->assets)
		return (0);

	//tiles are temp/ 2d view of map & player
	game->assets->background = make_tile(game->mlx, 0x808080FF);
	if (!game->assets->background)
		return (0);
	game->assets->wall = make_tile(game->mlx, 0xFF0000FF);
	if (!game->assets->wall)
		return (0);
	game->assets->player = make_tile(game->mlx, 0x0000FFFF);
	if (!game->assets->player)
		return (0);

	game->assets->fov = mlx_new_image(game->mlx, WIDTH, HEIGHT); // overlay image size of entire screen for the rays/fov
	if (!game->assets->fov)
		return 0;

	// init textures here
	game->assets->brick_wall = mlx_load_png("./src/textures/Brick_Wall_64x64.png");
	if (!game->assets->brick_wall)
	{
		ft_printf("wall texture didn't load\n");
		return (0);
	}

	game->assets->crack_wall = mlx_load_png("./src/textures/Brick_Wall_Cracked_64x64.png");
	if (!game->assets->crack_wall)
	{
		ft_printf("cracked wall texture didn't load\n");
		return (0);
	}
	return (1);
}

int	init_game(t_game *game, t_config *config)
{

	game->map = config->map;
	
	printf("in init game %f\n",game->player.pos_x);
	game->mlx = mlx_init(WIDTH, HEIGHT, "w0ffelstein", true);
	if (!game->mlx)
	{
		ft_printf("mlx_init failure\n");
		return (EXIT_FAILURE);
	}
	init_player(&game->player);
	game->player.pos_x = config->player_x;
	game->player.pos_y = config->player_y;
	if (!init_assets(game))
	{
		ft_printf("init_assets failure\n");
		return (EXIT_FAILURE);
	}
	// ft_printf("height is '%i'\n", co)
	// if (!init_map(game, map))
	// {
	// 	ft_printf("map init failure\n");
	// 	return (EXIT_FAILURE);
	// }
	render_map(game);
	return (EXIT_SUCCESS);
}
