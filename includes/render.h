/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 17:44:16 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/30 13:32:11 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// render.c
void		draw_pov(t_game *game);
void			draw_minimap(t_game *game, mlx_image_t *minimap);
void			draw_minimap_player(t_game *game);
void			images_to_window(t_game *game);

// images.c
void			clear_image(mlx_image_t *img);
void			draw_tile(mlx_image_t *minimap, int x, int y, uint32_t color);
void			draw_column(t_game *game, t_ray *ray, int x);
int				create_background_imgs(t_game *game, t_config *config);

// textures.c
int				load_textures(t_game *game, t_config *config);
uint32_t		get_texture_pixel(mlx_texture_t *tex, int x, int y);
mlx_texture_t	*pick_texture(t_game *game, t_ray *ray);

#endif // RENDER_H