/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 19:59:19 by rmhazres      #+#    #+#                 */
/*   Updated: 2025/11/13 13:11:16 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"
# include "typedefs.h"

// parse_config.c
int	extract_map(t_config *config, int i);
int	assign_config(t_config *config, int dir, char **arr);
int	extract_config(t_config *config, char *line, bool *seen);
int	parse_config(t_config *config);

int	parse_game(t_config *config);
int	arg_checker(int argc, char *argv[]);
int	get_file(char *path, t_config *config);
int	handle_input(int argc, char **argv, t_config *config);

#endif // PARSING_H