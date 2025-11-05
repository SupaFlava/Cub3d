/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaetsen <jbaetsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:16:37 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/05 16:04:37 by jbaetsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int argc, char **argv, t_config *config)
{
	if (!arg_checker(argc, argv))
		return (FAILURE);
	if (!get_file(argv[1], config))
		return (FAILURE);
	return (SUCCESS);
}
