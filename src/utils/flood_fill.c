/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:40:46 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/13 00:08:02 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	push_cell(t_point *stack, size_t *top, int y, int x)
{
	stack[*top].y = y;
	stack[*top].x = x;
	(*top)++;
}

static void	add_neighbor_if_valid(t_config *cfg, t_point *stack,
	size_t *top, size_t max, int y, int x)
{
	if (!is_inside_map(cfg, y, x) || *top >= max)
		return ;
	if (is_wall_or_visited(cfg->map.grid, y, x)
		|| is_space_cell(cfg->map.grid, y, x))
		return ;
	cfg->map.grid[y][x] = 'V';
	push_cell(stack, top, y, x);
}

static void	add_all_neighbors(t_config *cfg, t_point *stack,
	size_t *top, size_t max, int y, int x)
{
	add_neighbor_if_valid(cfg, stack, top, max, y - 1, x);
	add_neighbor_if_valid(cfg, stack, top, max, y + 1, x);
	add_neighbor_if_valid(cfg, stack, top, max, y, x - 1);
	add_neighbor_if_valid(cfg, stack, top, max, y, x + 1);
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
	t_point	*stack;
	t_point	cur;
	size_t	top;
	size_t	max;

	max = (size_t)cfg->map.width * (size_t)cfg->map.height;
	stack = malloc(sizeof(t_point) * max);
	if (!stack)
		return (FAILURE);
	cfg->open_found = false;
	top = 0;
	push_cell(stack, &top, start_y, start_x);
	cfg->map.grid[start_y][start_x] = 'V';
	while (top > 0)
	{
		cur = stack[--top];
		process_cell(cfg, cur.y, cur.x);
		add_all_neighbors(cfg, stack, &top, max, cur.y, cur.x);
	}
	free(stack);
	if (cfg->open_found)
		return (FAILURE);
	return (SUCCESS);
}
