/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:59:19 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/29 19:50:40 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"
# include "typedefs.h"

int	parse_game(t_config *config);
int	arg_checker(int argc, char *argv[]);
int	get_file(char *path, t_config *config);
int	parse_config(t_config *config);
int	handle_input(int argc, char **argv, t_config *config);

#endif // PARSING_H