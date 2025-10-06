/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:44:16 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/03 17:22:08 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// int		create_background_image(t_game *game);
// int		create_wall_image(t_game *game);
// int		create_player_image(t_game *game);
void		images_to_window(t_game *game);
void	render_map(t_game *game);
mlx_image_t	*make_tile(mlx_t *mlx, uint32_t color);
void draw_line(mlx_image_t *img, t_point start, t_point end, uint32_t color);
void	draw_player_rays(t_game *game);
void	update_player_rays(t_player *player);




#endif // RENDER_H