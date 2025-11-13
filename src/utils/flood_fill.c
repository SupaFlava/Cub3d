/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:40:46 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/12 15:44:47 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// static bool	is_valid_cell(t_config *config, int y, int x)
// {
// 	char	**map;

// 	map = config->map.grid;
// 	if (y < 0 || y >= config->map.height || x < 0)
// 		return (false);
// 	if (x >= (int)ft_strlen(map[y]))
// 		return (false);
// 	return (true);
// }

// static bool	handle_cell(t_config *config, int y, int x)
// {
// 	char	**map = config->map.grid;

// 	if (map[y][x] == '1' || map[y][x] == 'V')
// 		return (false);
// 	if (map[y][x] == ' ')
// 		return (true);
// 	map[y][x] = 'V';
// 	return (false);
// }

// static void	push_neighbors(t_point *stack,t_config *con, int y, int x)
// {
// 	if (con->top + 4 >= con->max)
// 		return ;
// 	stack[(con->top)++] = (t_point){y - 1, x};
// 	stack[con->top++] = (t_point){y + 1, x};
// 	stack[con->top++] = (t_point){y, x - 1};
// 	stack[con->top++] = (t_point){y, x + 1};
// }

// // int	flood_fill(t_config *config, int start_y, int start_x)
// // {
// // 	t_point	*stack;
// // 	t_point	p;

// // 	config->max = config->map.width * config->map.height;
// // 	stack = malloc(sizeof(t_point) * config->max);
// // 	if (!stack)
// // 		return (FAILURE);
// // 	stack[config->top++] = (t_point){start_y, start_x};
// // 	while (config->top > 0)
// // 	{
// // 		p = stack[--config->top];
// // 		if (!is_valid_cell(config, p.y, p.x))
// // 			continue ;
// // 		if (handle_cell(config, p.y, p.x))
// // 		{
// // 			config->open_found = true;
// // 			continue ;
// // 		}
// // 		push_neighbors(stack, config, p.y, p.x);
// // 	}
// // 	free(stack);
// // 	if (config->open_found)
// // 		return (FAILURE);
// // 	return (SUCCESS);
// // }
