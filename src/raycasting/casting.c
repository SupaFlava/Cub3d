/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 14:21:11 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/23 17:01:25 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays_loop(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		cast_single_ray(game, &game->player.rays[i]);
		i++;
	}
}

void	cast_single_ray(t_game *game, t_ray *ray)
{
	t_player *p;

	p = &game->player;
	// starting square
	ray->map_x = (int)p->pos_x;
	ray->map_y = (int)p->pos_y;

	check_ray_dir(ray);
	calc_side_dist(ray, p);
	perform_dda(game, ray);
	calc_perp_dist(ray, p);
	if (ray->perp_dist < 0.0) //dont allow negative values
		ray->perp_dist = 0.0;
}
