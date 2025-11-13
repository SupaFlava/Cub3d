/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/12 13:40:46 by rmhazres      #+#    #+#                 */
/*   Updated: 2025/11/13 16:40:24 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	push_cell(t_fill *fill, int y, int x)
{
	fill->stack[fill->top].y = y;
	fill->stack[fill->top].x = x;
	(fill->top)++;
}

static void	add_neighbor_if_valid(t_config *cfg, t_fill *fill, int y, int x)
{
	if (fill->top >= fill->max)
		return ;
	if (!is_inside_map(cfg, y, x))
	{
		cfg->open_found = true;
		return ;
	}
	if (is_wall_or_visited(cfg->map.grid, y, x))
		return ;
	if (is_space_cell(cfg->map.grid, y, x))
	{
		cfg->open_found = true;
		return ;
	}
	cfg->map.grid[y][x] = 'V';
	push_cell(fill, y, x);
}

static void	add_all_neighbors(t_config *cfg, t_fill *fill, int y, int x)
{
	add_neighbor_if_valid(cfg, fill, y - 1, x);
	add_neighbor_if_valid(cfg, fill, y + 1, x);
	add_neighbor_if_valid(cfg, fill, y, x - 1);
	add_neighbor_if_valid(cfg, fill, y, x + 1);
}

static bool	process_cell(t_config *cfg, int y, int x)
{
	char	**map;

	map = cfg->map.grid;
	if (is_wall_or_visited(map, y, x))
		return (false);
	if (is_space_cell(map, y, x))
	{
		cfg->open_found = true;
		return (true);
	}
	map[y][x] = 'V';
	return (false);
}

int	flood_fill(t_config *cfg, int start_y, int start_x)
{
	t_fill	fill;
	t_point	current;

	fill.top = 0;
	fill.max = (size_t)cfg->map.width * (size_t)cfg->map.height;
	fill.stack = malloc(sizeof(t_point) * fill.max);
	if (!fill.stack)
		return (FAILURE);
	fill.open_found = false;
	cfg->map.grid[start_y][start_x] = 'V';
	push_cell(&fill, start_y, start_x);
	while (fill.top > 0)
	{
		current = fill.stack[--fill.top];
		process_cell(cfg, current.y, current.x);
		add_all_neighbors(cfg, &fill, current.y, current.x);
	}
	free(fill.stack);
	if (cfg->open_found)
		return (FAILURE);
	return (SUCCESS);
}
