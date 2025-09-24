/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:59:19 by rmhazres          #+#    #+#             */
/*   Updated: 2025/09/24 18:43:34 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "cub3d.h"
#include "typedefs.h"

int arg_checker(int argc, char *argv[]);
int	get_cub(char *path, t_config *config);



#endif