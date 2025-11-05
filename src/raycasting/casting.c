/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:21:11 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/05 13:50:09 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays_loop(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		cast_single_ray(game, &game->player.rays[i]);
		i++;
	}
}

void	cast_single_ray(t_game *game, t_ray *ray)
{
	t_player	*p;

	p = &game->player;
	ray->map_x = (int)p->pos_x;
	ray->map_y = (int)p->pos_y;
	check_ray_dir(ray);
	calc_side_dist(ray, p);
	perform_dda(game, ray);
	calc_perp_dist(ray, p);
	if (ray->perp_dist < 0.0)
		ray->perp_dist = 0.0;
}
