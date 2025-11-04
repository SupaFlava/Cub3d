/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:16:37 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/04 11:20:27 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int argc, char **argv, t_config *config)
{
	if (arg_checker(argc, argv) == FAILURE)
		return (FAILURE);
	if (get_file(argv[1], config) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
