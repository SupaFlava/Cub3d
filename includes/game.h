/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 11:25:04 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/07 16:14:42 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"


// game.c
void	keyhook(mlx_key_data_t keydata, void *param);
void	game_loop(void *param);


// controls.c
void	check_rotation(t_game *game, double rot_step);
void	rotate_player(t_player *p, double angle);
void	check_movement(t_game *game, double move_step);

#endif // GAME_H