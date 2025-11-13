/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 12:22:42 by rmhazres      #+#    #+#                 */
/*   Updated: 2025/11/13 15:45:29 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# include "libft.h"

int		ft_isnl(char *string);
int		parse_color(t_config *config, char *colors, int dir);
int		classify_directive(char *dir);
bool	is_map_line(char *line);
void	set_position(t_config *config, int i, int j);
int		flood_fill(t_config *config, int start_y, int start_x);

// math_utils.c
int		my_abs(int num);

// set_dir.c
void	set_north(t_game *game);
void	set_south(t_game *game);
void	set_west(t_game *game);
void	set_east(t_game *game);

// memory_utils.c
char	*safe_assign(char *src, bool *err_flag);

// cleanup_utils.c
void	clean_split(char **alloc);
void	clean_config(t_config *config);

// controls_utils.c
void	wall_collision(t_game *game, double x, double y);
void	move_left(t_game *game, double move_step);
void	move_right(t_game *game, double move_step);
void	move_forward(t_game *game, double move_step);
void	move_back(t_game *game, double move_step);

// validate_utils.c
int		is_matching(char c);
int		open_and_close_file(char *path);
int		check_char(t_config *config, int i, int j);
int		ft_isnumeric(char **str);

// parse_config_utils.
int		get_count(t_config *config, int i);
int		process_config_lines(t_config *config, bool seen[6], int *i);
void	free_and_get_line(t_config *config, char **line, int *i);

// utils.c
int		init_config(t_config *config);
void	set_player_dir(t_game *game, char dir);
void	init_player(t_game *game, t_config *config);
int		init_assets(t_game *game, t_config *config);
int		init_game(t_game *game, t_config *config);
void	clean_game(t_game *game);
void	clean_cub3d(void *param, char *msg);

// flood_fill_utils.c
bool	is_inside_map(t_config *config, int y, int x);
bool	is_wall_or_visited(char **map, int y, int x);
bool	is_space_cell(char **map, int y, int x);

#endif // UTILS_H