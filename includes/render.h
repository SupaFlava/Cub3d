/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:44:16 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/11/10 19:19:38 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// render.c
void			draw_pov(t_game *game);
void			draw_minimap(t_game *game, mlx_image_t *minimap);
void			draw_minimap_player(t_game *game);
int				images_to_window(t_game *game);

// images.c
void			clear_image(mlx_image_t *img);
void			draw_tile(mlx_image_t *minimap, int x, int y, uint32_t color);
void			draw_column(t_game *game, t_ray *ray, int x);
int				create_background_imgs(t_game *game, t_config *config);

// textures.c
int				load_textures(t_game *game, t_config *config);
uint32_t		get_texture_pixel(mlx_texture_t *tex, int x, int y);
mlx_texture_t	*pick_texture(t_game *game, t_ray *ray);
void	init_textures(t_game *game);

// draw_column_utils.c
void			calc_wall_bounds(t_ray *ray, t_draw_info *info);
int				calc_text_x(t_game *game, t_ray *ray, mlx_texture_t *tex);
void			setup_text_sampling(t_draw_info *info, mlx_texture_t *tex);
void			draw_textured_column(t_game *game, mlx_texture_t *tex, int x,
					t_draw_info *info);

#endif // RENDER_H