/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:37:38 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/15 23:21:15 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

// casting.c
void	cast_rays(t_game *game);
void	diferential_analysis(t_game *game, t_ray *ray);

// rays.c
void 		draw_line(mlx_image_t *img, t_point start, t_point end, uint32_t color);
void		draw_player_rays(t_game *game);
void		update_player_rays(t_player *player);

#endif // RAYCASTING_H
