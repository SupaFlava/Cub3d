/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 17:44:16 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/01 15:32:39 by jbaetsen      ########   odam.nl         */
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


#endif // RENDER_H