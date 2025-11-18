/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_protected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:20:38 by rmhazres          #+#    #+#             */
/*   Updated: 2025/11/18 11:32:01 by rmhazres         ###   ########.fr       */
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
	long total;
	int digit;

	i = 0;
	total = 0;
	while (str[i] && c_isspace(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - 10;
		if (total > ( INT_MAX / 10) ||
			(total ==( INT_MAX / 10) && digit > (INT_MAX % 10)))
			return (-1);
		else
		{
			total = total * 10 + (str[i] - '0');
			i++;
		}
	}
	return ((int)total);
}
