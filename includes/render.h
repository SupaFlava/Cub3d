/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:44:16 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/22 16:48:29 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// render.c
void	render_map(t_game *game);
void	images_to_window(t_game *game);

// images.c
void		draw_column(t_game *game, t_ray *ray, int x);
int			create_floor_ceiling_images(t_game *game, t_config *config);
int			create_2dviewimages(t_game *game);
mlx_image_t	*make_tile(mlx_t *mlx, uint32_t color);


// textures.c
int			load_textures(t_game *game, t_config *config);
uint32_t	get_texture_pixel(mlx_texture_t *tex, int x, int y);
mlx_texture_t	*pick_texture(t_game *game, t_ray *ray);


#endif // RENDER_H