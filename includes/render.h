/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:44:16 by jbaetsen          #+#    #+#             */
/*   Updated: 2025/10/15 23:21:35 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// render.c
void		render_map(t_game *game);

// images.c
int	create_2dviewimages(t_game *game);
mlx_image_t	*make_tile(mlx_t *mlx, uint32_t color);


// textures.c
int	load_textures(t_game *game, t_config *config);


#endif // RENDER_H