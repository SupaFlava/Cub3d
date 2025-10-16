/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 17:44:16 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/16 16:32:27 by jbaetsen      ########   odam.nl         */
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


#endif // RENDER_H