/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:25:04 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/09 20:24:23 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

// game.c
void	keyhook(mlx_key_data_t keydata, void *param);
void	game_loop(void *param);

// controls.c
void	mouse_look(double y_pos, double x_pos, void *param);
void	check_mouse(t_game *game);
void	check_movement(t_game *game, double move_step);
void	check_rotation(t_game *game, double rot_step);
void	rotate_player(t_player *p, double angle);

#endif // GAME_H