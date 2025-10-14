/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 14:37:38 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/13 17:55:25 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

// rays.c


// casting.c
void	cast_rays(t_game *game);
void	diferential_analysis(t_game *game, t_ray *ray);

#endif // RAYCASTING_H
