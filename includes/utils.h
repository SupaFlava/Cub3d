/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:22:42 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/15 23:32:36 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# include "libft.h"

int ft_isspace(char *string);
int parse_color(t_config *config ,char *colors, int dir);
int classify_directive(char *dir);


//memory utils
char *safe_assign(char *src, bool *err_flag);

//clean up utils
void clean_split(char **alloc);
void	clean_config(t_config *config);

//validate utils
int	open_and_close_file(char *path);


// utils.c
int 	init_config(t_config *config);
void	set_player_dir(t_game *game, char dir);
void	init_player(t_game *game, t_config *config);
int		init_assets(t_game *game, t_config *config);
int		init_game(t_game *game, t_config *config);


#endif // UTILS_H