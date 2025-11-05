/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:37:38 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/05 14:09:04 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

// casting.c
void	cast_rays_loop(t_game *game);
void	cast_single_ray(t_game *game, t_ray *ray);

// rays.c
void	update_player_rays(t_player *player);
void	init_line_variables(t_point *d, t_point *s, t_point start, t_point end);
bool	is_in_bounds(mlx_image_t *img, t_point p);
void	draw_minimap_rays(t_game *game);
void	draw_line(mlx_image_t *img, t_point start, t_point end, uint32_t color);

// ray_math.c
void	check_ray_dir(t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	calc_perp_dist(t_ray *ray, t_player *p);
void	calc_side_dist(t_ray *ray, t_player *p);

#endif // RAYCASTING_H
