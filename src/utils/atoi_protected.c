/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_protected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:20:38 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/18 18:09:01 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c_isspace(char c)
{
	if (c == ' ')
		return (SUCCESS);
	return (FAILURE);
}

int	atoi_p(const char *str)
{
	int	i;
	int total;
	int guard;

	i = 0;
	guard = 0;
	total = 0;
	while (str[i] && c_isspace(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (guard > 2)
				return (-1);
		total = total * 10 + str[i] - '0';
		i++;
		guard++;
	}
	if (guard == 0)
		return (-1);
	return (total);
}
