/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmhazres <rmhazres@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/29 14:12:00 by rmhazres      #+#    #+#                 */
/*   Updated: 2025/10/23 17:18:29 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*safe_assign(char *src, bool *err_flag)
{
	char	*tmp;

	tmp = ft_strdup(src);
	if (tmp == NULL)
	{
		*err_flag = true;
		return (NULL);
	}
	return (tmp);
}
