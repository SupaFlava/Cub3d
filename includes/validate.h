/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:36:47 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/09 22:12:23 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "cub3d.h"

int	validate(t_config *config);
int	validate_map(t_config *config);
char	*getnl_string(char *src, int *i);
int	empty_line(char **str);

#endif