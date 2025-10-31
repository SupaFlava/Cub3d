/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbaetsen <jbaetsen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/30 14:15:52 by jbaetsen      #+#    #+#                 */
/*   Updated: 2025/10/30 16:47:40 by jbaetsen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}
