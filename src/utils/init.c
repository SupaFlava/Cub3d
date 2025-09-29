/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/26 13:51:59 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/09/29 22:59:13 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player)
{
	player->pos_x = 100;
	player->pos_y = 100;
	player->dir_x = 1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.66;
	player->move_speed = 200.0;
	player->rot_speed = 1.00;
}

int	init_assets(t_game *game)
{
	game->assets = malloc(sizeof(t_assets));
	if (!game->assets)
		return (0);
	create_background_image(game);
	if (!game->assets->background)
		return (0);
	create_player_image(game);
	if (!game->assets->player)
		return (0);
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
	images_to_window(game);
	return (EXIT_SUCCESS);
}
