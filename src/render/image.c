/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 16:46:18 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/09/29 22:57:10 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_background_image(t_game *game)
{
	game->assets->background = mlx_new_image(game->mlx, 1920, 1080);
	if (!game->assets->background)
		return (0);
	memset(game->assets->background->pixels, 0, 1920 * 1080 * BPP);
	return (1);
}

int	create_player_image(t_game *game)
{
	game->assets->player = mlx_new_image(game->mlx, 50, 50);
	if (!game->assets->player)
		return (0);
	memset(game->assets->player->pixels, 255, 50 * 50 * BPP);
	return (1);
}

void	images_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->assets->background, 0, 0);
	mlx_image_to_window(game->mlx, game->assets->player,
		(int)game->player.pos_x,
		(int)game->player.pos_y);
}
