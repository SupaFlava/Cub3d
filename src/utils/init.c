/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/26 13:51:59 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/08 13:36:28 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//dummy map for testing - remove later
static const char *raw_map[] = {
    "111111111111111111111111111111",
	"100000000000000000000000000001",
	"10000N111111111110000000000001",
	"100000000000000000000000100001",
	"100000000000000000001000000001",
	"100000000111111000000010000001",
	"100000000000001000000000000001",
	"100000000000001000000000010001",
	"100000000000001000000000000001",
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
	while (raw_map[h])
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

// units are tiles per second, pos_x * TILE_SIZE == pixel value
// direction vectors://
// (dir_x, dir_y)
// (1, 0) = facing east
// (-1, 0) = facing west
// (0, 1) = facing south
// (0, -1) = facing north
void	init_player(t_player *player)
{
	player->pos_x = 1.0;
	player->pos_y = 1.0;
	player->dir_x = 0.0;
	player->dir_y = -1.0;
	player->plane_y = 0.0;
	player->plane_x = 0.66; // fov
	player->move_speed = 3.0;
	player->rot_speed = 3.0;


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

	game->assets->fov = mlx_new_image(game->mlx, WIDTH, HEIGHT); // overlay image size of entire screen for the rays/fov
	if (!game->assets->fov)
		return 0;


	return (1);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "w0ffelstein", true);
	if (!game->mlx)
	{
		ft_printf("mlx_init failure\n");
		return (EXIT_FAILURE);
	}
	init_player(&game->player);
	if (!init_assets(game))
	{
		ft_printf("init_assets failure\n");
		return (EXIT_FAILURE);
	}
	if (!init_map(game))
	{
		ft_printf("map init failure\n");
		return (EXIT_FAILURE);
	}

	render_map(game);
	return (EXIT_SUCCESS);
}
