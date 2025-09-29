/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 17:44:16 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/09/29 23:03:08 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

int		create_background_image(t_game *game);
int		create_player_image(t_game *game);
void	images_to_window(t_game *game);

#endif // RENDER_H