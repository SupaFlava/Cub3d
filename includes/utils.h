/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/26 12:48:06 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/09/29 23:07:29 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# include "libft.h"

// utils.c
void	init_player(t_player *player);
int		init_assets(t_game *game);
int		init_game(t_game *game);

#endif // UTILS_H