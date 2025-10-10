/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:03:14 by rmhazres          #+#    #+#             */
/*   Updated: 2025/10/10 14:05:18 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_extention(char *file)
{
	int		len;
	int		i;
	char	*extention;
	
	extention =	".cub";
	len = ft_strlen(file);
	if(len < 4)
	{
	ft_putstr_fd("invalid file\n", STDOUT_FILENO);
		return (FAILURE);
	}
	len = len -4;
	i = 0;
	while(file[len])
	{
		if(file[len] != extention[i])
			return (ft_printf("Error\nInvalid extention\n"), FAILURE);
		i++;
		len++;
	}
	return(SUCCESS);
}

int arg_checker(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("error wrong num of args\n", STDOUT_FILENO);
		return (FAILURE);
	}
	check_extention(argv[1]);
	return (SUCCESS);
}
