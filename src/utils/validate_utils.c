/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 18:23:52 by rmhazres      #+#    #+#                 */
/*   Updated: 2025/10/23 17:22:25 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_and_close_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR\n");
		close(fd);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}
