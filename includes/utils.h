/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:22:42 by rmhazres          #+#    #+#             */
/*   Updated: 2025/09/30 11:25:24 by rmhazres         ###   ########.fr       */
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


// utils.c
void	init_player(t_player *player);
int		init_assets(t_game *game);
int		init_game(t_game *game);

#endif // UTILS_H