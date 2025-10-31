/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 11:25:04 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/31 16:12:08 by jbaetsen      ########   odam.nl         */
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
void	check_rotation(t_game *game, double rot_step);
void	check_movement(t_game *game, double move_step);
void	rotate_player(t_player *p, double angle);

// collision.c
int		is_solid_tile(t_game *game, int target_x, int target_y);
void	wall_collision(t_game *game, double x, double y);

#endif // GAME_H