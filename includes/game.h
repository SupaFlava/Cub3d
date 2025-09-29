/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 11:25:04 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/09/29 23:02:39 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

void	keyhook(mlx_key_data_t keydata, void *param);
void	game_loop(void *param);

#endif // GAME_H