/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/26 12:46:41 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/09/26 14:42:14 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyhook(mlx_key_data_t keydata, void* param) // registers escape key only for now
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("CLOSING\nescape key pressed\n");
		exit(EXIT_SUCCESS);
	}
}
